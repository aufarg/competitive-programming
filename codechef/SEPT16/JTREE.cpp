#include <bits/stdc++.h>

using namespace std;

#define INF 10000000000000000LL
#define MAXN 100000

struct SegTree {
    SegTree *lft, *rgt;
    int lb, rb;
    long long v;
    SegTree(int l, int r)
    {
        lb = l; rb = r; v = 0;
        if (l == r) {
            lft = rgt = NULL;
        }
        else {
            int mid = (l+r)/2;
            lft = new SegTree(l, mid); rgt = new SegTree(mid+1, r);
        }
    }

    void Update(int x, long long c)
    {
        if (x < lb || x > rb) return;
        else if (x == lb && x == rb) v = c;
        else {
            lft->Update(x, c);
            rgt->Update(x, c);
            v = min(lft->v, rgt->v);
        }
    }

    long long Query(int l, int r)
    {
        assert(l <= r);
        if (r < lb || l > rb) return INF;
        else if (l <= lb && rb <= r) return v;
        else return min(lft->Query(l, r), rgt->Query(l, r));
    }

    ~SegTree()
    {
        if (lft != NULL) delete lft;
        if (rgt != NULL) delete rgt;
    }
};

vector<int> edge[MAXN+5];

struct Ticket
{
    int cap, cost;
    Ticket(int a, int b)
    {
        cap = a;
        cost = b;
    }
};

long long ans[MAXN+5];
vector<Ticket> tickets[MAXN+5];

void dfs(int v, int lv, SegTree *root)
{
    if (v != 1) ans[v] = INF;
    for (auto &t: tickets[v]) {
        int cap = t.cap;
        long long tcost = root->Query(max(lv-cap,1), max(lv-1,1));
        ans[v] = min(ans[v], tcost + t.cost);
    }
    root->Update(lv, ans[v]);

    for (auto &u: edge[v]) {
        dfs(u, lv+1, root);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        tickets[a].push_back(Ticket(b,c));
    }

    SegTree *root = new SegTree(1, n);
    dfs(1, 1, root);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
