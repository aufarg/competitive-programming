#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define MAXN 500
int prv[MAXN+5], dist[MAXN+5];
vector<int> edge[MAXN+5];

struct Edge
{
    int f, t, c, a, w;
    Edge(int _f, int _t, int _c, int _w): f(_f), t(_t), c(_c), a(_c), w(_w) {}
};

vector<Edge> edges;

typedef pair<int, int> State;

pair<int,int> mcmf(int n, int s, int t)
{
    int mf = 0, mc = 0;
    while (true) {
        set<State> S;
        fill(dist, dist+n, INF);
        S.insert(make_pair(0, s));
        dist[s] = 0;
        int flow = INF;
        while (!S.empty()) {
            State top = *S.begin();
            S.erase(top);
            int v = top.second;
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edges[edge[v][i]];
                if (v == e.f && dist[e.t] > dist[v]+e.w && e.a > 0) {
                    S.erase(make_pair(dist[e.t], e.t));
                    dist[e.t] = dist[v]+e.w;
                    prv[e.t] = edge[v][i];
                    S.insert(make_pair(dist[e.t], e.t));
                }
                if (v == e.t && dist[e.f] > dist[v]-e.w && e.a < e.c) {
                    S.erase(make_pair(dist[e.f], e.f));
                    dist[e.f] = dist[v]-e.w;
                    prv[e.f] = edge[v][i];
                    S.insert(make_pair(dist[e.f], e.f));
                }
            }
        }
        if (dist[t] == INF) break;
        int cost = dist[t];
        int v = t;
        while (v != s) {
            Edge &e = edges[prv[v]];
            if (v == e.f) {
                v = e.t;
                flow = min(flow, e.c-e.a);
            }
            else {
                v = e.f;
                flow = min(flow, e.a);
            }
        }
        v = t;
        while (v != s) {
            Edge &e = edges[prv[v]];
            if (v == e.f) {
                v = e.t;
                e.a += flow;
            }
            else {
                v = e.f;
                e.a -= flow;
            }
        }
        mf += flow;
        mc += flow*cost;
    }
    return make_pair(mf, mc);
}

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        scanf("%d%d%d%d", &u, &v, &c, &w);
        edge[u].push_back(edges.size());
        edge[v].push_back(edges.size());
        edges.push_back(Edge(u, v, c, w));
    }
    pair<int,int> ret = mcmf(n, s, t);
    printf("%d %d\n", ret.first, ret.second);
    return 0;
}
