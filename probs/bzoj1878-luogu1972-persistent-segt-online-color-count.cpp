#include <bits/stdc++.h>
#define rep(i_,s_,t_) for(int i_=(s_);i_<=(t_);++i_)
#define re(i_,s_,t_) for(int i_=(s_);i_<(t_);++i_)
#define per(i_,s_,t_) for(int i_=(s_);i_>=(t_);--i_)
#define pe(i_,s_,t_) for(int i_=(s_);i_>(t_);--i_)
#define koishi(e_,u_) for(Edge *e_=(u)_->e;e_;e_=e_->e)
#ifdef AKARI
    void c_() { std::cerr << "\033[39;0m" << std::endl; }
    template<typename T, typename... Args>
    void c_(T a, Args... args) { std::cerr << a << ", "; c_(args...); }
    #define ccc(args...) std::cerr << "\033[32;1m" << #args << "  =  ", c_(args)
    #define ccd(args...) std::cerr << "\033[32;1m", c_(args)
    #define ccf(args...) fprintf(stderr, args)
    #define crep(i_,s_,t_) for(int i_=(s_);i_<=(t_);++i_)
#else
    #define ccc(...) 0
    #define ccd(...) 0
    #define ccf(...) 0
    #define crep(...) if (false)
#endif
typedef long long ll;
typedef const int cint;
typedef const long long cll;
typedef const char cchar;
#define oper operator
#define daze << '\n'
cint p_[]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};template<cint LI,cint LO>struct IO{char a[LI],b[LO],r[30],*s,*t,*z,c;IO():z(b){}~IO(){if(z!=b)fwrite(b,1,z-b,stdout);}char gc(){if(s==t)t=(s=a)+fread(a,1,LI,stdin);return s==t?EOF:*s++;}template<class T>IO&oper>>(T&x){for(c=gc();c!='-'&&!isdigit(c);c=gc());bool f=c=='-';if(f)c=gc();x=c-'0';for(c=gc();isdigit(c);c=gc())x=x*10+(c-'0');if(f)x=-x;return*this;}IO&oper>>(char*x){for(c=gc();!isgraph(c);c=gc());*x++=c;for(c=gc();isgraph(c);*x++=c,c=gc());*x=0;return*this;}IO&oper>>(char&x){for(x=gc();!isgraph(x);x=gc());return*this;}IO&oper>>(double&x){int p,y;*this>>p;if(c=='.'){*this>>y;for(x=y;x>1;x/=10);if(p<0)x=p-x;else x+=p;}else x=p;return*this;}template<class T>oper T(){T x;*this>>x;return x;}void pc(cchar x){if(z==b+LO)fwrite(z=b,1,LO,stdout);*z++=x;}void fl(){fwrite(b,1,z-b,stdout);z=b;}template<class T>struct d{T x;int l;d(const T x_,cint l_):x(x_),l(l_){}oper T&(){return x;}};template<class T>d<T>operator()(const T x,cint l){return d<T>(x,l);}template<class T>IO&oper<<(T x){if(x==0)pc('0');else{if(x<0)pc('-'),x=-x;T y;char*j=r;for(;x;x=y)y=x/10,*j++=x-y*10+'0';while(j!=r)pc(*--j);}return*this;}template<class T>IO&oper<<(d<T>x){if(x==0)re(i,0,x.l)pc('0');else{if(x<0)pc('-'),x.x=-x;T y;char*j=r;for(;x;x.x=y,--x.l)y=x/10,*j++=x-y*10+'0';for(;x.l;pc('0'),--x.l);while(j!=r)pc(*--j);}return*this;}IO&oper<<(d<double>x){if(std::isnan(x))return*this<<"nan";if(std::isinf(x))return*this<<"inf";if(x<0)pc('-'),x.x=-x;int w=floor(x);*this<<w;pc('.');int e=(x-w)*p_[x.l],u=e/10;if(e-u*10>=5)++u;return*this<<d<int>(u,x.l);}IO&oper<<(const double x){return*this<<d<double>(x,6);}IO&oper<<(char*x){while(*x)pc(*x++);return*this;}IO&oper<<(cchar*x){while(*x)pc(*x++);return*this;}IO&oper<<(cchar x){return pc(x),*this;}template<class T>void oper()(T x){*this<<x;}};
IO<1000000, 1000000> io;

cint N = 50003, LGN = 20, V = 1000003;  // for luogu N = 500003
int mx;
struct Node *nil;
struct Node {
    Node *lc, *rc;
    int sum;
    Node() {}
    Node(cint s) : lc(nil), rc(nil), sum(s) {}
    Node(Node *l, Node *r) : lc(l), rc(r), sum(l->sum + r->sum) {}
    void *operator new (size_t) {
        static Node pool[N * LGN], *curr = pool;
        return curr++;
    }
    Node *insert(cint qi, cint l = 0, cint r = mx) const {
        if (l == r)
            return new Node(sum + 1);
        int mid = (l + r) >> 1;
        if (qi <= mid)
            return new Node(lc->insert(qi, l, mid), rc);
        else
            return new Node(lc, rc->insert(qi, mid + 1, r));
    }
    int query(cint qr, cint l = 0, cint r = mx) const { // ql = 0
        if (r <= qr)
            return sum;
        int mid = l + r >> 1, res = lc->query(qr, l, mid);
        if (qr > mid)
            res += rc->query(qr, mid + 1, r);
        return res;
    }
} *segt[N];
int query(cint l, cint r) {
    return segt[r]->query(l - 1) - segt[l - 1]->query(l - 1);
}
int n, pos[V], pre[N];
int main() {
    nil = new Node;
    nil->lc = nil->rc = nil;

    io >> n;
    rep (i, 1, n) {
        int x(io);
        mx = std::max(mx, pre[i] = pos[x]);
        pos[x] = i;
    }
    segt[0] = nil;
    rep (i, 1, n)
        segt[i] = segt[i - 1]->insert(pre[i]);
    int m = io;
    while (m--) {
        int l(io);
        io << query(l, io) daze;
    }
    return 0;
}

