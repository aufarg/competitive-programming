#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define EPS 1e-9

const double PI = acos(-1.0);

pair<int,int> node[MAXN+5];
vector<int> edge[MAXN+5];
int vis[MAXN+5][MAXN+5];

long long sqr(long a) { return a*a; }
double dist(int i, int j)
{
    return sqrt(sqr(node[i].first-node[j].first)+sqr(node[i].second-node[j].second));
}

double angle (int i, int j, int k)
{
    int dxij = node[j].first-node[i].first;
    int dyij = node[j].second-node[i].second;
    int dxjk = node[k].first-node[j].first;
    int dyjk = node[k].second-node[j].second;

    long long dot = dxij*dxjk+dyij*dyjk;
    double ljk = dist(j, k);
    double lij = dist(i, j);
    double cos = (double)dot/(ljk*lij);
    return acos(cos);
}

int main()
{
    int n, m, a;
    int s, f;
    scanf("%d%d%d%d%d", &n, &m, &a, &s, &f);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        node[i] = make_pair(x, y);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    priority_queue<pair<double, pair<int, int> > > PQ;
    for (int i = 0; i < edge[s].size(); ++i) {
        PQ.push(make_pair(-dist(s, edge[s][i]), make_pair(edge[s][i], s)));
        vis[s][edge[s][i]] = 1;
    }
    bool found = false;
    double ans;
    while (!PQ.empty()) {
        int v = PQ.top().second.first;
        int p = PQ.top().second.second;
        double d = -PQ.top().first;
        PQ.pop();
        if (vis[v][p]) continue;
        vis[v][p] = 1;
        if (v == f) {
            if (!found) ans = d;
            else ans = fmin(ans, d);
            found = true;
        }
        for (int i = 0; i < edge[v].size(); ++i) {
            int u = edge[v][i];
            double ang = angle(p, v, u);
            if (180.0*ang/PI <= (double)a+EPS) {
                PQ.push(make_pair(-(d+dist(v, u)), make_pair(u, v)));
            }
        }
    }
    if (found) printf("%.3lf\n", ans);
    else puts("-1");
    return 0;
}
