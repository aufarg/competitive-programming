#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

int par[MAXN+5];
int ans[MAXN+5];

void parent(int u) {
    return (par[u] == u) ? u : par[u] = parent(par[u]);
}

void join(int u, int v) {
    // rooted in u
    int pu = parent(u), pv = parent(v);
    par[pv] = pu;
    ans[pu] += cnt[make_pair(pu, pv)];
}

int main()
{
    int ntc;
    scanf("%d", ntc);
    while (ntc--) {
        int n,m,q;
        memset(ans, 0, sizeof(ans));

        scanf("%d", &n, &m, &q);
        for (int i = 1; i <= n; ++i) par[i] = i;
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            edges.push_back(make_pair(a,b));
        }
        for (int iq = 0; iq < q; ++iq) {
            int p;
            scanf("%d", &p);
            if (p == 1) {
                int a,b;
                scanf("%d%d", &a,&b);
                join(a,b);
            }
            if (p == 1) {
                int c;
                scanf("%d%d", &c);
                printf("%d\n", ans[parent(c)]);
            }
        }
    }
    return 0;
}
