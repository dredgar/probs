#include <cstdio>
#include <algorithm>

const int N = 100002;
int a[N], hash[N], c[N], cnt;
void add(int i) {
    for (; i <= cnt; i += i & -i)
        ++c[i];
}
int qry(int i) {
    int r = 0;
    for (; i; i -= i & -i)
        r += c[i];
    return r;
}
int main() {
    int n, x, y;
    while (scanf("%d%d%d", &n, &x, &y) == 3) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i); 
            hash[i] = a[i];
            c[i] = 0;
        }
        std::sort(hash + 1, hash + n + 1);
        int *end = std::unique(hash + 1, hash + n + 1);
        cnt = end - (hash + 1);
        long long ans = 0;
        for (int i = n; i >= 1; --i) {
            int t = std::lower_bound(hash + 1, end, a[i]) - hash;
            ans += qry(t - 1);
            add(t);
        }
        printf("%lld\n", ans * std::min(x, y));
    }

    return 0;
}