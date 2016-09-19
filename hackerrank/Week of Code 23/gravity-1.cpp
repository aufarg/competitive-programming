#include <bits/stdc++.h>

using namespace std;

#define LOGN 20
#define MAXN 100000

vector<int> edge[MAXN+5];
int par[MAXN+5][LOGN];
int lv[MAXN+5];
long long sqd[MAXN+5], td[MAXN+5], cnt[MAXN+5];
long long usqd[MAXN+5], utd[MAXN+5], ucnt[MAXN+5];

struct RET
{
    long long sqd, td, cnt;
    RET(long long a, long long b, long long c)
    {
        sqd = a, td = b, cnt = c;
    }
};

RET dfs(int v, int d)
{
    lv[v] = d;
    for (auto &u: edge[v]) {
        RET ret = dfs(u, d+1);
        td[v] += ret.td + ret.cnt;
        sqd[v] += ret.sqd + 2*ret.td+ret.cnt;
        cnt[v] += ret.cnt;
    }
    ++cnt[v];
    return RET(sqd[v], td[v], cnt[v]);
}

int lca(int v, int u)
{
    if (lv[v] < lv[u]) swap(u, v);
    int k = lv[v]-lv[u];
    int r = 0;
    while (k) {
        if (k%2) v = par[v][r];
        k >>= 1, ++r;
    }
    if (v == u) return v;

    assert(lv[u] == lv[v]);
    r = 0;
    while (par[v][r] != par[u][r]) ++r;
    for (; r >= 0; --r) {
        if (par[v][r] != par[u][r]) {
            v = par[v][r];
            u = par[u][r];
        }
    }

    return par[v][0];
}

void fill(int v, long long vsqd, long long vtd, long long vcnt)
{
    usqd[v] = vsqd, utd[v] = vtd, ucnt[v] = vcnt;
    for (auto &u: edge[v]) {
        long long csqd = sqd[u]+2*td[u]+cnt[u];
        long long ctd = td[u]+cnt[u];
        long long ccnt = cnt[u];

        long long ncnt = (vcnt)+cnt[v]-ccnt;
        long long ntd = (vtd+vcnt)+(td[v]-ctd)+(cnt[v]-ccnt);
        long long nsqd = (vsqd+2*vtd+vcnt)+sqd[v]-csqd+2*(td[v]-ctd)+cnt[v]-ccnt;
        fill(u, nsqd, ntd, ncnt);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    par[1][0] = -1;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &par[i+1][0]);
        edge[par[i+1][0]].push_back(i+1);
    }
    dfs(1, 0);
    fill(1, 0, 0, 0);
    int q;
    scanf("%d", &q);
    for (int j = 1; j < LOGN; ++j)
        for (int i = 1; i <= n; ++i)
            par[i][j] = par[par[i][j-1]][j-1];

    for (int qq = 0; qq < q; ++qq) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == v) {
            printf("%lld\n", sqd[u]);
            continue;
        }
        int p = lca(u, v);
        if (p != u && p != v) {
            long long dist = lv[u]+lv[v]-2*lv[p];
            printf("%lld\n", sqd[v]+2*dist*td[v]+dist*dist*cnt[v]);
        }
        else if (p == u) {
            long long dist = lv[v]-lv[u];
            printf("%lld\n", sqd[v]+2*dist*td[v]+dist*dist*cnt[v]);
        }
        else {
            long long dist = lv[u]-lv[v];
            printf("%lld\n", sqd[u] + usqd[u] - (usqd[v]+2*dist*utd[v]+dist*dist*ucnt[v]));
        }
    }
    return 0;
}
