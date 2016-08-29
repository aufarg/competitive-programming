#include <bits/stdc++.h>

using namespace std;

#define ROOT 1
#define MAXN 10000
#define LOGN 15

int n;
int u[MAXN+5], v[MAXN+5], w[MAXN+5];
int par[MAXN+5][LOGN+5], lv[MAXN+5], size[MAXN+5];
int costPar[MAXN+5];
vector<int> edge[MAXN+5], cost[MAXN+5];

struct SegTree {
    SegTree *lft, *rgt;
    int val;
    int lbound, rbound;
    SegTree(int l, int r, vector<int> &v)
    {
        lbound = l; rbound = r;
        if (l == r) {
            lft = rgt = NULL;
            val = v[l];
        }
        else {
            int mid = (l+r)/2;
            lft = new SegTree(l, mid, v);
            rgt = new SegTree(mid+1, r, v);
            val = max(lft->val, rgt->val);
        }
    }

    void Del()
    {
        if (lft != NULL) {
            lft->Del();
            delete lft;
        }
        if (rgt != NULL) {
            rgt->Del();
            delete rgt;
        }
    }

    int Query(int l, int r)
    {
        if (l > r) return 0;
        if (lbound >= l && rbound <= r) return val;
        if (r < lbound || l > rbound) return 0;
        return max(lft->Query(l,r), rgt->Query(l,r));
    }

    int Update(int x, int c)
    {
        if (lbound == x && rbound == x) {
            return val = c;
        }
        else if (lbound > x || rbound < x) return val;
        else {
            return val = max(lft->Update(x,c),rgt->Update(x,c));
        }
    }
};

int dfs(int v, int l)
{
    size[v] = 0;
    lv[v] = l;
    for (int i = 0; i < edge[v].size(); ++i) {
        int u = edge[v][i];
        int c = cost[v][i];
        if (u != par[v][0]) {
            par[u][0] = v;
            size[v] += dfs(u, l+1);
        }
        else {
            costPar[v] = c;
        }
    }
    return ++size[v];
}

int lca(int u, int v)
{
    if (lv[u] > lv[v]) swap(u, v);
    int log = LOGN;

    for (int i = log; i >= 0; --i) {
        if (par[v][i] != -1 && lv[v]-lv[u] >= (1<<i)) {
            v = par[v][i];
        }
    }

    if (u == v) return u;

    for (int i = log; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int chainId = 0;
int pos[MAXN+5], chainNum[MAXN+5], chainVPrev[MAXN+5];
vector<int> chains[MAXN+5];
SegTree *stree[MAXN+5];

void chaining(int v)
{
    int maxsize = 0;
    int u = -1;
    pos[v] = chains[chainId].size();
    chainNum[v] = chainId;
    chains[chainId].push_back(costPar[v]);

    for (int i = 0; i < edge[v].size(); ++i) {
        int w = edge[v][i];
        if (w != par[v][0] && maxsize < size[w]) {
            maxsize = size[w];
            u = w;
        }
    }
    if (u != -1) {
        chaining(u);
    }

    for (int i = 0; i < edge[v].size(); ++i) {
        int w = edge[v][i];
        if (w != u && w != par[v][0]) {
            ++chainId;
            chainVPrev[chainId] = v;
            chaining(w);
        }
    }
}

int query(int v, int p)
{
    int ans = 0;
    while (chainNum[v] != chainNum[p]) {
        ans = max(ans, stree[chainNum[v]]->Query(0, pos[v]));
        v = chainVPrev[chainNum[v]];
    }
    if (v != p) {
        assert(lv[p] < lv[v]);
        ans = max(ans, stree[chainNum[v]]->Query(pos[p]+1, pos[v]));
    }
    return ans;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int a,b,c;
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            edge[u[i]].push_back(v[i]);
            edge[v[i]].push_back(u[i]);
            cost[u[i]].push_back(w[i]);
            cost[v[i]].push_back(w[i]);
        }

        memset(par, -1, sizeof(par));

        dfs(ROOT, 0);
        chaining(ROOT);
        for (int j = 0; (1<<j) <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (par[i][j-1] != -1)
                    par[i][j] = par[par[i][j-1]][j-1];

            }
        }

        for (int i = 0; i <= chainId; ++i) {
            if (chains[i].size()) {
                stree[i] = new SegTree(0, chains[i].size(), chains[i]);
            }
        }

        char buf[256];
        while (scanf("%s", buf), buf[0] != 'D') {
            if (buf[0] == 'Q') {
                int a, b;
                scanf("%d%d", &a, &b);
                int p = lca(a,b);
                assert(p > 0);
                printf("%d\n", max(query(a, p), query(b, p)));
            }
            else {
                int i, ti;
                scanf("%d%d", &i, &ti);
                int a = v[i], b = u[i];
                if (lv[a] > lv[b]) swap(a,b);
                stree[chainNum[b]]->Update(pos[b], ti);
            }
        }

        for (int i = 0; i <= chainId; ++i) {
            if (chains[i].size()) {
                stree[i]->Del();
                chains[i].clear();
            }
        }
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
