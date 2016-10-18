#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define MAXN 200

struct Edge {
    int t, c, w, r;
};

int dist[MAXN+5], curf[MAXN+5], prv[MAXN+5], pot[MAXN+5];
bool vis[MAXN+5];
vector<Edge> edge[MAXN+5];

pair<int,int> mcmf(int n, int s, int t)
{
    int mf = 0, mc = 0;
    while (true) {
        priority_queue<pair<int,int> > PQ;
        PQ.push(make_pair(0, s));
        fill(dist, dist+n+1, INF);
        fill(vis, vis+n+1, false);
        curf[s] = INF;
        dist[s] = 0;
        while (!PQ.empty()) {
            pair<int,int> top = PQ.top();
            int v = top.second;
            int d = -top.first;
            PQ.pop();
            if (vis[v]) continue;
            vis[v] = true;
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edge[v][i];
                int ndist = dist[v] + e.w + pot[v] - pot[e.t];
                if (e.c > 0 && ndist < dist[e.t]) {
                    dist[e.t] = ndist;
                    curf[e.t] = min(curf[v], e.c);
                    prv[e.t] = e.r;
                    PQ.push(make_pair(-ndist, e.t));
                }
            }
        }
        if (dist[t] == INF) break;
        for (int i = 1; i <= n; ++i) pot[i] += dist[i];
        for (int v = t; v != s; v = edge[v][prv[v]].t) {
            Edge &e = edge[v][prv[v]];
            Edge &r = edge[e.t][e.r];
            e.c += curf[t];
            r.c -= curf[t];
            mc += r.w * curf[t];
        }
        mf += curf[t];
    }
    return make_pair(mc, mf);
}

void addEdge(int f, int t, int c, int w)
{
    Edge a = { t, c, w, (int)edge[t].size() };
    Edge b = { f, 0, -w, (int)edge[f].size() };
    edge[f].push_back(a);
    edge[t].push_back(b);
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n+m+2; ++i) edge[i].clear();
        int a, b, c;
        while (scanf("%d%d%d", &a, &b, &c), a != 0 || b != 0 || c != 0) {
            addEdge(a, n+b, 1, 100-c);
        }
        int s = n+m+1, t = n+m+2;
        for (int i = 1; i <= n; ++i) addEdge(s, i, 1, 0);
        for (int i = 1; i <= m; ++i) addEdge(n+i, t, 1, 0);
        pair<int,int> ret = mcmf(n+m+2, s, t);
        printf("%d\n", 100*ret.second-ret.first);
    }
    return 0;
}
