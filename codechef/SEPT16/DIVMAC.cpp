#include <bits/stdc++.h>

using namespace std;

#define MAXV 1000000
#define MAXN 100000

int n, m;
int prime[MAXV+5], a[MAXN+5];
int nxt[MAXN+5], prv[MAXN+5];

struct segtree {
    segtree *lft, *rgt;
    int lb, rb;
    int val;
    segtree(int l, int r)
    {
        lb = l; rb = r;
        if (l == r) {
            lft = rgt = NULL;
            val = prime[a[l]];
        }
        else {
            int mid = (l+r)/2;
            lft = new segtree(l, mid); rgt = new segtree(mid+1, r);
            val = max(lft->val, rgt->val);
        }
    }

    void update(int p, int v)
    {
        if (p < lb || p > rb) return;
        if (lb == rb) {
            val = v;
        }
        else {
            lft->update(p, v); rgt->update(p, v);
            val = max(lft->val, rgt->val);
        }
    }

    int query(int l, int r)
    {
        if (r < lb || l > rb) return 0;
        if (l <= lb && rb <= r) return val;
        return max(lft->query(l, r), rgt->query(l, r));
    }

    ~segtree() {
        if (lft != NULL) {
            delete lft;
        }
        if (rgt != NULL) {
            delete rgt;
        }
    }
};

int find(int v)
{
    if (v > n || a[v] != 1) return v;
    else return nxt[v] = find(nxt[v]);
}

int main()
{
    prime[1] = 1;
    for (int i = 2; i*i <= MAXV; ++i) {
        if (!prime[i]) {
            int t = i*i;
            while (t <= MAXV) {
                if (!prime[t]) prime[t] = i;
                t += i;
            }
        }
    }
    for (int i = 2; i <= MAXV; ++i)
        if (!prime[i]) prime[i] = i;

    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int space = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            nxt[i] = i+1;
        }

        segtree *root = new segtree(1, n);
        for (int q = 0; q < m; ++q) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            if (t == 0) {
                int p = l;
                while (p <= r) {
                    a[p] /= prime[a[p]];
                    root->update(p, prime[a[p]]);
                    p = find(nxt[p]);
                }
            }
            else {
                if (space) printf(" ");
                space = 1;
                printf("%d", root->query(l, r));
            }
        }
        puts("");
        delete root;
    }
}
