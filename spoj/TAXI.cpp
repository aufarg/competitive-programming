#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define MAXN 800

struct Edge
{
    int t, c, r;
};

int x[MAXN+5], y[MAXN+5];
int vis[MAXN+5], prv[MAXN+5], curf[MAXN+5];
vector<Edge> edge[MAXN+5];


int maxflow(int n, int s, int t)
{
    int mf = 0;
    while (true) {
        queue<int> Q;
        Q.push(s);
        fill(vis, vis+n, false);
        fill(curf, curf+n, INF);
        vis[s] = true;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edge[v][i];
                if (!vis[e.t] && e.c > 0) {
                    curf[e.t] = min(curf[s], e.c);
                    prv[e.t] = e.r;
                    vis[e.t] = true;
                    Q.push(e.t);
                }
            }
        }
        if (curf[t] == INF) break;
        for (int v = t; v != s; v = edge[v][prv[v]].t) {
            Edge &e = edge[v][prv[v]];
            Edge &r = edge[e.t][e.r];
            e.c += curf[t];
            r.c -= curf[t];
        }
        mf += curf[t];
    }
    return mf;
}
void add(int f, int t, int c)
{
    Edge a = { t, c, (int)edge[t].size() };
    Edge b = { f, 0, (int)edge[f].size() };
    edge[f].push_back(a);
    edge[t].push_back(b);
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int p, t, s, c;
        scanf("%d%d%d%d", &p, &t, &s, &c);
        int nodes = 0;
        int so = p+t, si = p+t+1;
        for (int i = 0; i < p+t+2; ++i) edge[i].clear();
        for (int i = 0; i < p; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            add(so, i, 1);
        }
        for (int j = 0; j < t; ++j ){
            int a, b;
            scanf("%d%d", &a, &b);
            add(j+p, si, 1);
            for (int i = 0; i < p; ++i) {
                int d = abs(a-x[i])+abs(b-y[i]);
                if (d*200 > s*c) continue;
                add(i, j+p, 1);
            }
        }
        printf("%d\n", maxflow(p+t+2, so, si));
    }
    return 0;
}
