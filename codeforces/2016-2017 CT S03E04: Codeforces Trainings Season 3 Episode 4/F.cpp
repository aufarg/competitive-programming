#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define MAXD 20
#define MAXT 300

int n, m;
int grid[MAXD+5][MAXD+5], vis[MAXD+5][MAXD+5], mvis[MAXD*MAXD+5], prv[MAXD*MAXD+5];
int cap[MAXD*MAXD+5][MAXD*MAXD+5], cost[MAXD*MAXD+5][MAXD*MAXD+5];
int nnode[MAXD+5][MAXD+5];

int dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};

int maxflow(int n, int s, int t, int th)
{
    int mf = 0;
    while (true) {
        memset(mvis ,0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        mvis[s] = 1;
        prv[t] = -1;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            if (v == t) break;
            for (int i = 0; i < n; ++i) {
                if (!mvis[i] && cap[v][i] > 0 && cost[v][i] <= th) {
                    mvis[i] = 1;
                    prv[i] = v;
                    Q.push(i);
                }
            }
        }
        if (prv[t] == -1) break;
        int flow = INF;
        for (int v = t; v != s; v = prv[v]) {
            int u = prv[v];
            flow = min(cap[u][v], flow);
        }
        for (int v = t; v != s; v = prv[v]) {
            cap[prv[v]][v] -= flow;
            cap[v][prv[v]] += flow;
        }
        mf += flow;
    }
    return mf;
}

void BFS(int r, int c, int id)
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, pair<int, int> > > Q;
    Q.push(make_pair(0,make_pair(r,c)));
    vis[r][c] = 1;
    while (!Q.empty()) {
        int d = Q.front().first;
        int rr = Q.front().second.first;
        int cc = Q.front().second.second;
        Q.pop();
        if (nnode[rr][cc] != -1) {
            cost[id][nnode[rr][cc]] = d;
            cost[nnode[rr][cc]][id] = d;
            cap[id][nnode[rr][cc]] = 1;
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = rr+dr[i], nc = cc+dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                if (!vis[nr][nc] && grid[nr][nc] != 'X') {
                    vis[nr][nc] = 1;
                    Q.push(make_pair(d+1, make_pair(nr, nc)));
                }
            }
        }
    }
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d%d", &n, &m);
        memset(nnode, -1, sizeof(nnode));
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));
        int doors = 0, peops = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j];
                if (grid[i][j] == 'D') {
                    nnode[i][j] = doors++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    BFS(i, j, doors+peops++);
                }
            }
        }

        int s = doors+peops, t = doors+peops+1;
        int n = doors+peops+2;
        int mf = 0;
        for (int i = 0; i < peops; ++i) {
            cap[s][i+doors] = 1;
        }
        for (int tm = 1; tm <= MAXT; ++tm) {
            for (int i = 0; i < doors; ++i) if(!cap[i][t]) cap[i][t] = 1;
            mf += maxflow(n, s, t, tm);
            if (mf == peops) {
                printf("%d\n", tm);
                goto end;
            }
        }
        puts("impossible");
end:
        {}
    }
    return 0;
}
