#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MAXN 1000

class RookAttack
{
    public:
        int grid[MAXN+5][MAXN+5];
        int adj[MAXN+5][MAXN+5];
        int vis[MAXN+5], prev[MAXN+5];
        int maxflow(int n, int s, int t)
        {
            int mf = 0;
            while (true) {
                queue<pair<int,int> > Q;
                fill(vis, vis+n, 0);
                Q.push(make_pair(s, INF));
                vis[s] = 1;
                int flow = INF;
                while (!Q.empty()) {
                    int v = Q.front().first;
                    int f = Q.front().second;
                    Q.pop();
                    if (v == t) flow = f;
                    for (int i = 0; i < n; ++i) {
                        if (!vis[i] && adj[v][i] > 0) {
                            Q.push(make_pair(i, min(f, adj[v][i])));
                            vis[i] = 1;
                            prev[i] = v;
                        }
                    }
                }
                if (flow == INF) break;
                int v = t;
                while (v != s) {
                    adj[v][prev[v]] += flow;
                    adj[prev[v]][v] -= flow;
                    v = prev[v];
                }
                mf += flow;
            }
            return mf;
        }
        int howMany(int r, int c, vector<string> x)
        {
            for (int i = 0; i < x.size(); ++i) {
                for (int j = 0; j < x[i].size(); ++j) if (x[i][j] == ',') x[i][j] = ' ';
                stringstream ss(x[i]);
                int a, b;
                while (ss >> a >> b) {
                    grid[a][b] = 1;
                }
            }
            int s = r+c;
            int t = r+c+1;
            int n = r+c+2;
            for (int i = 0; i < r; ++i) {
                adj[s][i] = 1;
                for (int j = 0; j < c; ++j) adj[r+j][t] = 1;

                for (int j = 0; j < c; ++j) {
                    if (!grid[i][j]) {
                        adj[i][r+j] = 1;
                    }
                }
            }
            return maxflow(n, s, t);
        }
};
