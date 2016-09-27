#include <bits/stdc++.h>

using namespace std;

#define MAXN 500

int par[MAXN+5];
vector<pair<int, pair<int,int> > > edge;

int find(int v)
{
    if (par[v] != v) par[v] = find(par[v]);
    return par[v];
}

int join(int u, int v)
{
    int pu = find(u), pv = find(v);
    par[pu] = pv;
}

void setds(int n)
{
    for (int i = 1; i <= n; ++i) par[i] = i;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    setds(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        edge.push_back(make_pair(c,make_pair(u, v)));
    }
    sort(edge.begin(), edge.end());
    vector<int> mst;
    for (int i = 0; i < m; ++i) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if (find(u) != find(v)) {
            join(u,v);
            mst.push_back(i);
        }
    }

    int a = 0, b = 0;
    for (int i = 0; i < mst.size(); ++i) {
        setds(n);
        int w = edge[mst[i]].first;
        for (int j = 0; j < mst.size(); ++j) {
            if (i == j) continue;
            int jj = mst[j];
            int u = edge[jj].second.first;
            int v = edge[jj].second.second;
            if (find(u) != find(v)) join(u, v);
        }
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            int u = edge[j].second.first;
            int v = edge[j].second.second;
            if (j != mst[i] && edge[j].first == w && find(u) != find(v)) {
                ok = false;
            }
        }
        if (ok) {
            a++;
            b+=w;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
