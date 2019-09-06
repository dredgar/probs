#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

#define rep(i_, s_, t_) for (int i_ = (s_); i_ <= (t_); ++i_)
#define re(i_, s_, t_) for (int i_ = (s_); i_ < (t_); ++i_)
#define per(i_, s_, t_) for (int i_ = (s_); i_ >= (t_); --i_)
#define pe(i_, s_, t_) for (int i_ = (s_); i_ > (t_); --i_)
#define daze << '\n'

#ifdef AKARI
void cca() {
    std::cerr << "\033[39;0m" << std::endl;
}
template <typename T, typename... Args>
void cca(T a, Args... args) {
    std::cerr << a << ", ";
    cca(args...);
}
    #define ccc(args...) std::cerr << "\033[32;1m" << #args << "  =  ", cca(args)
    #define ccf(args...) std::fprintf(stderr, args)
    #define crep(i_, s_, t_) rep(i, s_, t_)
#else
    #define ccc(...) 0
    #define ccf(...) 0
    #define crep(...) if (0)
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef const int cint;
typedef const ll cll;
typedef const char cchar;
typedef const uint cuint;
typedef const ull cull;

template <int I, int O>
struct IO {
    char r[20];
#ifdef AKARI
    char gc() {
        return std::getchar();
    }
    void pc(cchar c) {
        std::putchar(c);
    }
#else
    char a[I], b[O], *s, *t, *z;
    std::streambuf *i, *o;
    IO() : z(b) {
        std::ios::sync_with_stdio(false);
        if (I) std::cin.tie(NULL), i = std::cin.rdbuf();
        if (O) std::cout.tie(NULL), o = std::cout.rdbuf();
    }
    ~IO() {
        if (O) o->sputn(b, z - b);
    }
    char gc() {
        if (s == t) t = (s = a) + i->sgetn(a, I);
        return *s++;
    }
    void pc(cchar c) {
        if (z == b + O) o->sputn(z = b, O);
        *z++ = c;
    }
#endif
    char *gs(char *p) {
        char c;
        while (!std::isgraph(c = gc()));
        while (*p++ = c, std::isgraph(c = gc()));
        return *p = 0, p;
    }
    IO &operator >> (char *p) {
        char c;
        while (!std::isgraph(c = gc()));
        while (*p++ = c, std::isgraph(c = gc()));
        return *p = 0, *this;
    }
    IO &operator >> (char &c) {
        while (!std::isgraph(c = gc()));
        return *this;
    }
    template <class T>
    IO &operator >> (T &x) {
        char c;
        while (!std::isdigit(c = gc()) && c != '-');
        if (c == '-')
            for (x = '0' - gc(); std::isdigit(c = gc()); x = x * 10 + ('0' - c));
        else
            for (x = c - '0'; std::isdigit(c = gc()); x = x * 10 + (c - '0'));
        return *this;
    }
    template <class T>
    operator T () {
        T x;
        return *this >> x, x;
    }
    IO &operator << (char *p) {
        while (*p) pc(*p++);
        return *this;
    }
    IO &operator << (cchar *p) {
        while (*p) pc(*p++);
        return *this;
    }
    IO &operator << (cchar c) {
        return pc(c), *this;
    }
    template <class T>
    IO &operator << (T x) {
        if (x < 0) pc('-'), x = -x;
        else if (x == 0) return pc('0'), *this;
        char *j = r;
        while (*j++ = x % 10 + '0', x /= 10);
        while (pc(*--j), j != r);
        return *this;
    }
};
