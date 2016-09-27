#include <bits/stdc++.h>

using namespace std;

#define INF 10000000LL
#define MAXN 50

class Parking
{
    public:
        bool gvis[MAXN+5][MAXN+5];
        bool vis[6*MAXN+5];
        int node[MAXN+5][MAXN+5];
        int prev[6*MAXN+5];
        int res[6*MAXN+5][6*MAXN+5];
        int dist[6*MAXN+5][6*MAXN+5];
        pair<int,int> mcmf(int n, int s, int t)
        {
            int mf = 0;
            int mc = 0;
            while (true) {
                priority_queue<pair<pair<int,int>, pair<int, int> > > PQ;
                fill(vis, vis+n, false);
                PQ.push(make_pair(make_pair(0, INF), make_pair(s, -1)));
                int cost = 0, flow = INF;
                while (!PQ.empty()) {
                    pair<pair<int,int>, pair<int,int> > top = PQ.top();
                    int c = -top.first.first;
                    int f = top.first.second;
                    int v = top.second.first;
                    int p = top.second.second;
                    PQ.pop();
                    if (vis[v]) continue;
                    vis[v] = true;
                    prev[v] = p;
                    if (v == t) {
                        cost = c;
                        flow = f;
                        break;
                    }
                    for (int i = 0; i < n; ++i) {
                        if (!vis[i] && res[v][i] > 0) PQ.push(make_pair(make_pair(-max(c,dist[v][i]), min(f, res[v][i])), make_pair(i, v)));
                    }
                }
                if (flow == INF) break;
                int v = t;
                while (v != s) {
                    int p = prev[v];
                    res[p][v] -= flow;
                    res[v][p] += flow;
                    v = p;
                }
                mf += flow;
                mc = max(mc, cost);
                assert(flow == 1);
            }
            return make_pair(mf, mc);
        }
        void bfs(int r, int c, int v, vector<string> &grid)
        {
            int n = grid.size(), m = grid[0].size();
            queue<pair<int, pair<int,int> > > Q;
            Q.push(make_pair(0, make_pair(r, c)));
            memset(gvis, 0, sizeof(gvis));
            gvis[r][c] = true;
            while (!Q.empty()) {
                pair<int,int> g = Q.front().second;
                int d = Q.front().first;
                int i = g.first, j = g.second;
                Q.pop();
                if (grid[i][j] == 'P') {
                    dist[v][node[i][j]] = d;
                    dist[node[i][j]][v] = d;
                    res[v][node[i][j]] = 1;
                }
                int dr[] = { 1, 0, -1, 0 };
                int dc[] = { 0, 1, 0, -1 };
                for (int k = 0; k < 4; ++k) {
                    int ni = i+dr[k], nj = j+dc[k];
                    if (0 <= ni && 0 <= nj && ni < n && nj < m && !gvis[ni][nj] && grid[ni][nj] != 'X') {
                        gvis[ni][nj] = true;
                        Q.push(make_pair(d+1, make_pair(ni, nj)));
                    }
                }
            }
        }
        int minTime(vector<string> grid)
        {
            int n = grid.size(), m = grid[0].size();
            int nnode = 0, cars = 0;
            memset(node, -1, sizeof(node));
            memset(dist, -1, sizeof(dist));
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'P') node[i][j] = nnode++;
            }
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'C') {
                    ++cars;
                    bfs(i, j, node[i][j] = nnode++, grid);
                }
            }
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'P') res[node[i][j]][nnode+1] = 1;
                if (grid[i][j] == 'C') res[nnode][node[i][j]] = 1;
            }
            pair<int,int> ret = mcmf(nnode+2, nnode, nnode+1);
            if (ret.first == cars) return ret.second;
            else return -1;
        }
};
