#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int v[MAXN+5];
vector<int> edge[MAXN+5];
vector<int> cost[MAXN+5];

#define INF 1500000000
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int ans = INF;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        v[a] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < edge[i].size(); ++j) {
            if (v[i] ^ v[edge[i][j]]) {
                ans = min(ans, cost[i][j]);
            }
        }
    }
    if (ans == INF) puts("-1");
    else printf("%d\n", ans);
    return 0;
}
