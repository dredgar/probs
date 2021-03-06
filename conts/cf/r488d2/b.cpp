#include <bits/stdc++.h>
#define rep(__i,__s,__t) for((__i)=(__s);(__i)<=(__t);++(__i))
#define re(__i,__s,__t) for((__i)=(__s);(__i)<(__t);++(__i))
#define per(__i,__s,__t) for((__i)=(__s);(__i)>=(__t);--(__i))
#define pe(__i,__s,__t) for((__i)=(__s);(__i)>(__t);--(__i))
#ifdef AKARI
    #define ccc(x) std::cerr << #x " = " << (x) << "  "
    #define ccf(x) std::cerr << #x " = " << (x) << std::endl
    #define cccc(...) fprintf(stderr, __VA_ARGS__)
#else
    #define ccc(x)
    #define ccf(x)
    #define cccc(...)
#endif
struct IO{static const int L=1000000;char a[L],b[L],*s,*t,*p,c;IO():p(b){}~IO(){fwrite(b,1,p-b,stdout);}char gc(){if(s==t)t=(s=a)+fread(a,1,L,stdin);return*s++;}void gs(char*st){for(c=gc();!isgraph(c);c=gc());*st++=c;for(c=gc();isgraph(c);c=gc())*st++=c;*st++=0;}template<class T>operator T(){static T x;static bool neg;for(c=gc();c!='-'&&!isdigit(c);c=gc());if((neg=c=='-'))c=gc();x=c-'0';for(c=gc();isdigit(c);c=gc())x=x*10+(c-'0');return neg?-x:x;}void pc(const char ch){if(p==b+L)fwrite(p=b,1,L,stdout);*p++=ch;}template<class T>void print(T x,const char end='\n'){static char cs[30],*q;static T y;if(x==0)pc('0');else{if(x<0)pc('-'),x=-x;for(q=cs;x;x=y)y=x/10,*q++=x-y*10+'0';while(q!=cs)pc(*--q);}if(end)pc(end);}void ps(const char*st,const char end='\n'){while(*st)pc(*st++);if(end)pc(end);}}io;
typedef long long ll;

const int N = 100003;
int n, k, p[N], c[N], sa[N];
ll ans[N];
bool cmp(int i, int j) {
    return p[i]<p[j];
}
std::priority_queue<int> q;
ll ksum() {
    static int tmp[30];
    int cnt = 0, x;
    ll res = 0;
    while (!q.empty()) {
        x = q.top();
        q.pop();
        res += x;
        tmp[++cnt] = x;
        if (cnt >= k)
            break;
    }
    rep (x, 1, cnt)
        q.push(tmp[x]);
    return res;
}
int main() {
    static int i;
    n = io;
    k = io;
    rep (i, 1, n)
        p[i] = io;
    rep (i, 1, n)
        c[i] = io;
    rep (i, 1, n)
        sa[i] = i;
    std::sort(sa+1,sa+n+1,cmp);
    rep (i,1,n) {
        ans[sa[i]] = ksum();
        q.push(c[sa[i]]);
    }
    rep (i, 1, n)
        io.print(ans[i]+c[i], i==n?'\n':' ');

    return 0;
}

