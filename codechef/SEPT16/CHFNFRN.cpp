#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
vector<int> edge[MAXN+5];
int col[MAXN+5], e[MAXN+5][MAXN+5];
int dfs(int v, int c)
{
    if (col[v] != -1) {
        return (col[v] == c);
    }
    col[v] = c;
    int ans = 1;
    for (int i = 0; i < edge[v].size(); ++i) {
        ans &= dfs(edge[v][i], !c);
    }
    return ans;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        memset(e, 0, sizeof(e));
        memset(col, -1, sizeof(col));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            e[a][b] = 1;
            e[b][a] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            for (int j = 1; j <= n; ++j) {
                if (i != j && e[i][j] == 0) edge[i].push_back(j);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (col[i] == -1) {
                if (!dfs(i, 0)) goto nope;
            }
        }
        puts("YES");
        continue;
nope:
        puts("NO");
    }
    return 0;
}
