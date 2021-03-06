#include <bits/stdc++.h>
#define rep(__i,__s,__t) for((__i)=(__s);(__i)<=(__t);++(__i))
#define re(__i,__s,__t) for((__i)=(__s);(__i)<(__t);++(__i))
#define per(__i,__s,__t) for((__i)=(__s);(__i)>=(__t);--(__i))
#define pe(__i,__s,__t) for((__i)=(__s);(__i)>(__t);--(__i))
#ifdef AKARI
    #define ccc(x) std::cerr << #x " = " << x << "  "
    #define cccc(x) std::cerr << #x " = " << x << std::endl
    #define ccccc(x) std::cerr << x << std::endl
#else
    #define ccc(x) 0
    #define cccc(x) 0
    #define ccccc(x) 0
#endif
typedef long long ll;

struct IO {
    static const int L = 1000000;
    char a[L], b[L], *s, *t, *p;
    IO() : p(b) {}
    ~IO() {
        fwrite(b, 1, p - b, stdout); // p = b;
    }
    char gc() {
        if (s == t)
            t = (s = a) + fread(a, 1, L, stdin);
        return *s++; // return s == t ? EOF : *s++;
    }
    void gs(char *st) {
        static char c;
        for (c = gc(); !isgraph(c); c = gc());
        *st++ = c;
        for (c = gc(); isgraph(c); c = gc())
            *st++ = c;
        *st++ = 0;
    }
    template <class T>
    operator T() {
        static T x;
        static char c;
        static bool neg;
        for (c = gc(); c != '-' && !isdigit(c); c = gc());
        if ((neg = c == '-'))
            c = gc();
        x = c - '0';
        for (c = gc(); isdigit(c); c = gc())
            x = x * 10 + (c - '0');
        return neg ? -x : x;
    }
    void pc(const char c) {
        if (p == b + L)
            fwrite(p = b, 1, L, stdout);
        *p++ = c;
    }
    template<class T>
    void print(T x, const char end = '\n') {
        static char c[30], *q;
        static T y;
        if (x == 0)
            pc('0');
        else {
            if (x < 0)
                pc('-'), x = -x;
            for (q = c; x; x = y)
                y = x / 10, *q++ = x - y * 10 + '0';
            while (q != c)
                pc(*--q);
        }
        if (end)
            pc(end);
    }
    void ps(const char *st, const char end = '\n') {
        while (*st)
            pc(*st++);
        if (end)
            pc(end);
    }
} io;

const int N = 5002, M = 10002;
struct Node {
    int dfn, low, bel;
    bool ins;
    struct Edge *e, *fe;
} g[N];
struct Edge {
    Node *v;
    Edge *e, *r;
    Edge() {}
    Edge(Node *_u, Node *_v) : v(_v), e(_u->e) {
        _u->e = this;
    }
} pool[M * 2], *curr = pool;
void arc(Node *u, Node *v) {
    new (curr++) Edge(u, v);
    new (curr++) Edge(v, u);
    (u->e->r = v->e)->r = u->e;
}
int bcnt, deg[N];
std::stack<Node *> s;
void tarjan(Node *u) {
    static int tim;
    u->low = u->dfn = ++tim;
    s.push(u);
    u->ins = true;
    Node *v;
    for (Edge *e = u->e; e; e = e->e) if (e->r != u->fe) {
        if (!(v = e->v)->dfn) {
            v->fe = e;
            tarjan(v);
            u->low = std::min(u->low, v->low);
            // if (v->low > u->dfn) // equal not included. consider multi edges between two vertice.
            //     e->is_cut = e->r->is_cut = true;
        } else // if (v->ins)  // This check is optional, but when finding SCCs it's required, as low[] has different definition at the two cases.
            u->low = std::min(u->low, v->dfn);
    }
    if (u->low == u->dfn) {
        ++bcnt;
        do {
            v = s.top();
            s.pop();
            v->ins = false;
            v->bel = bcnt;
        } while (u != v);
    }
}
std::pair<Node *, Node *> qwq[M];
int main() {
    static int n, m, i, cnt;
    n = io;
    m = io;
    rep (i, 1, m) {
        qwq[i] = std::make_pair(&g[(int)io], &g[(int)io]);
        arc(qwq[i].first, qwq[i].second);
    }
    rep (i, 1, n)
        if (!g[i].dfn)
            tarjan(&g[i]);
    rep (i, 1, m)
        if (qwq[i].first->bel != qwq[i].second->bel)
            ++deg[qwq[i].first->bel], ++deg[qwq[i].second->bel];   // **** deg of bcc.
    rep (i, 1, bcnt)
        if (deg[i] == 1)
            ++cnt;
    io.print((cnt + 1) >> 1);

    return 0;
}
