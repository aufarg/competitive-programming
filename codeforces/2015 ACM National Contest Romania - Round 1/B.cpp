#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
int vis[MAXN+5];
vector<int> edge[MAXN+5], cost[MAXN+5], idx[MAXN+5];

int main()
{
    freopen("algoritm.in", "r", stdin);
    freopen("algoritm.out", "w", stdout);

    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            edge[i].clear();
            cost[i].clear();
            idx[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[a].push_back(b);
            cost[a].push_back(c);
            idx[a].push_back(i+1);
        }
        vector<int> ans;
        priority_queue<pair<long long,pair<int,int>>> pq;
        pq.push(make_pair(0, make_pair(1, 0)));
        while (!pq.empty()) {
            int v = pq.top().second.first;
            long long c = -pq.top().first;
            int id = pq.top().second.second;
            if (id > 0) ans.push_back(id);
            pq.pop();
            if (vis[v]) continue;
            vis[v] = 1;
            for (int i = 0; i < edge[v].size(); ++i) {
                pq.push(make_pair(-(c+cost[v][i]), make_pair(edge[v][i], idx[v][i])));
            }
        }
        int space = 0;
        for (auto &idx: ans) {
            if (space) printf(" ");
            space = 1;
            printf("%d", idx);
        }
        puts("");
    }
    return 0;
}
