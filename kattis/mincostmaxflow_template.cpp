#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int from, int to, int cap, int flow, int cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

struct MCMF {
  int n, s, t;
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< int > dist;
  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }
  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  int augment(int v, int minflow = inf) {
    if(v == s) {
      return minflow;
    }
    if(par[v] < 0) {
      return 0;
    }
    int flow;
    Edge &e = vEdge[par[v]];
    if(v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    }
    else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }
  int findingPath() {
    //dijkstra
    set< pair< int , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while(!st.empty()) {
      set< pair< int, int > >::iterator begin = st.begin();
      int v = begin->second;
      st.erase(begin);
      for(int i = 0; i<adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if(e.from == v) {
          if(e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
            st.erase(make_pair(dist[e.to], e.to));
            dist[e.to] = dist[v] + e.cost;
            st.insert(make_pair(dist[e.to], e.to));
            par[e.to] = adj[v][i];
          }
        }
        else {
          if(e.flow > 0 && dist[e.from] > dist[v] - e.cost) {
            st.erase(make_pair(dist[e.from], e.from));
            dist[e.from] = dist[v] - e.cost;
            st.insert(make_pair(dist[e.from], e.from));
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    return augment(t, inf);
  }
  pair< int, int > EdmondKarp() {
    int maxflow = 0, mincost = 0;
    int flow;
    while(flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    struct MCMF mcmf = MCMF(n, s, t);
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        scanf("%d%d%d%d", &u, &v, &c, &w);
        mcmf.addEdge(u, v, c, w);
    }
    pair<int,int> ret = mcmf.EdmondKarp();
    printf("%d %d\n", ret.second, ret.first);
}
