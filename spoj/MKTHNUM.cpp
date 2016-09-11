#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

struct SegTree;

SegTree *rev[4*MAXN+5];
int a[4*MAXN+5];

struct SegTree
{
    SegTree *lft, *rgt;
    int ll, rr;
    int val;
    SegTree(int l, int r, int id)
    {
        ll = l, rr = r; val = a[ll];
        if (l == r) lft = rgt = NULL;
        else {
            int mid = (l+r)/2;
            lft = new SegTree(l, mid, 2*id);
            rgt = new SegTree(mid+1, r, 2*id+1);
            val = lft->val + rgt->val;
        }
        rev[id] = this;
    }

    SegTree(int l, int r, int x, int id)
    {
        ll = l; rr = r; val = a[ll];
        if (l == r) lft = rgt = NULL;
        else {
            int mid = (l+r)/2;
            if (x <= mid) {
                lft = new SegTree(l, mid, x, 2*id);
                rgt = rev[2*id+1];
            }
            else {
                lft = rev[2*id];
                rgt = new SegTree(mid+1, r, x, 2*id+1);
            }
            val = lft->val + rgt->val;
        }
        rev[id] = this;
    }

    int Query(int l, int r)
    {
        if (r < ll || l > rr) return 0;
        else if (l <= ll && rr <= r) return val;
        else return lft->Query(l, r) + rgt->Query(l, r);
    }

    ~SegTree()
    {
        if (lft != NULL) delete lft;
        if (rgt != NULL) delete rgt;
    }
};

SegTree *root[MAXN+5];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> srt;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        srt.push_back(make_pair(a[i], i));
        a[i] = 0;
    }

    sort(srt.begin(), srt.end());
    root[0] = new SegTree(0, n-1, 1);
    for (int i = 0; i < n; ++i) {
        int idx = srt[i].second;
        a[idx] = 1;
        root[i+1] = new SegTree(0, n-1, idx, 1);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        --a; -- b;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            int sum = root[mid]->Query(a, b);
            if (sum < k) l = mid+1;
            else r = mid;
        }
        for (; root[l]->Query(a,b) >= k; --l);
        for (; root[l]->Query(a,b) < k; ++l);
        printf("%d\n", srt[l-1].first);
    }
    return 0;
}
