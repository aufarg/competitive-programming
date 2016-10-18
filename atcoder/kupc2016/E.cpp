#include <bits/stdc++.h>

using namespace std;

#define INF 100000
#define MAXN 25000
#define MAXD 200

struct Edge
{
    int t, c, r;
};

char grid[MAXD+5][MAXD+5];
int w, h;
int prv[MAXN+5], vis[MAXN+5];
vector<Edge> edge[MAXN+5];

int get(int r, int c)
{
    if (r < 0 || r >= h || c < 0 || c >= w) return w*h*2+1;
    return 2*(r*w+c);
}

int add(int f, int t, int c)
{
    Edge a = { t, c, (int)edge[t].size() };
    Edge b = { f, 0, (int)edge[f].size() };
    edge[f].push_back(a);
    edge[t].push_back(b);
}

int maxflow(int n, int s, int t)
{
    int mf = 0;
    while (true) {
        queue<int> Q;
        Q.push(s);
        fill(vis, vis+n, false);
        vis[s] = true;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edge[v][i];
                if (!vis[e.t] && e.c > 0) {
                    vis[e.t] = true;
                    prv[e.t] = e.r;
                    Q.push(e.t);
                }
            }
        }
        if (!vis[t]) break;
        int flow = INF;
        for (int v = t; v != s; v = edge[v][prv[v]].t) {
            Edge &e = edge[v][prv[v]];
            Edge &r = edge[e.t][e.r];
            flow = min(flow, r.c);
        }
        for (int v = t; v != s; v = edge[v][prv[v]].t) {
            Edge &e = edge[v][prv[v]];
            Edge &r = edge[e.t][e.r];
            e.c += flow;
            r.c -= flow;
        }
        mf += flow;
    }
    return min(mf, INF);
}

int main()
{
    scanf("%d%d", &h, &w);
    int s = 2*h*w, t = 2*h*w+1;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) grid[i][j] = s[j];
    }

    int dr[] = {1,-1,0,0}, dc[] = {0,0,-1,1};
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            int idx = get(r,c);
            if (grid[r][c] == 'X') {
                add(s, idx, INF);
                add(idx, idx+1, INF);
            }
            else add(idx, idx+1, 1);
            for (int d = 0; d < 4; ++d) {
                int nr = r+dr[d], nc = c+dc[d];
                int nidx = get(nr, nc);
                add(idx+1, nidx, INF);
            }
        }
    }
    int f = maxflow(2*h*w+2, s, t);
    printf("%d\n", (f == INF) ? -1 : f);
    return 0;
}
