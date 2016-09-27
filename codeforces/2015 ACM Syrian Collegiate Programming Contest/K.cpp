#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
vector<int> edge[MAXN+5];
int d[MAXN+5], dv[MAXN+5];
int dfs(int v)
{
    d[v] = 0;
    for (auto &u: edge[v]) {
        d[v] = max(d[v], dfs(u)+1);
    }
    return d[v];
}

int dfs2(int v, int pd)
{
    dv[v] = max(d[v], pd);
    int bc = 0;
    int sc = 0;
    for (int i = 0; i < edge[v].size(); ++i) {
        int u = edge[v][i];
        if (d[u] > d[bc]) {
            sc = bc;
            bc = u;
        }
        else if (d[u] == d[bc]) sc = bc;
        else if (d[u] > d[sc]) sc = u;
    }
    for (int i = 0; i < edge[v].size(); ++i) {
        int u = edge[v][i];
        if (u == bc) dfs2(u, max(pd, d[sc]+1)+1);
        else dfs2(u, max(pd, d[bc]+1)+1);
    }
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int c, k;
        scanf("%d%d", &c, &k);
        double a = 0, b = 0, ps = MAXN;
        for (int t = 0; t < c; ++t){
            int n;
            scanf("%d", &n);
            d[0] = -1;
            for (int i = 1; i <= n; ++i) {
                edge[i].clear();
                d[i] = 0;
            }
            for (int i = 2; i <= n; ++i) {
                int a;
                scanf("%d", &a);
                edge[a].push_back(i);
            }
            dfs(1);
            dfs2(1, 0);
            int suc = 0, fail = 0;
            for (int i = 1; i <= n; ++i) {
                if (dv[i] > k) ++fail;
                else ++suc;
            }

            double p_suc = (double)suc*ps/n, p_fail = (double)fail*ps/n;
            a += p_fail;
            b += p_fail * 4 + p_suc;
            ps = p_suc;
        }
        a = (double)MAXN - a;
        printf("%.4lf\n", b/a);
    }
}
