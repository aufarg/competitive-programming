#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define NOL (make_pair(0,0))

pair<int,int> getr[MAXN+5];

pair<int,int> add(pair<int,int> p, pair<int,int> q)
{
    return make_pair(p.first+q.first, p.second+q.second);
}

pair<int,int> get(int x)
{
    int t = 0, f = 0;
    while (x%2==0) {
        ++t;
        x /= 2;
    }
    while (x%5==0) {
        ++f;
        x /= 5;
    }
    return make_pair(t, f);
}

struct SegTree {
    int l, r, br;
    SegTree *lft, *rgt;
    pair<int,int> val, upd, bv;
    bool lz;

    SegTree(int ll, int rr, vector<int> &v)
    {
        l = ll; r = rr; lz = false; br = -1; bv = NOL;
        if (ll == rr) {
            lft = rgt = NULL;
            val = get(v[ll]);
        }
        else {
            int m = (ll+rr)/2;
            lft = new SegTree(ll,m,v); rgt = new SegTree(m+1,rr,v);
            val = add(lft->val, rgt->val);
        }
    }
    void Lz()
    {
        if (lz) {
            int n = r-l+1;
            if (br != -1) {
                int cf = getr[r-br+1].first-getr[l-br].first;
                int cs = getr[r-br+1].second-getr[l-br].second;
                val = make_pair(cf+n*bv.first, cs+n*bv.second);
            }
            if (lft != NULL) {
                if (br != -1) {
                    lft->bv = bv;
                    lft->br = br;
                    lft->upd = NOL;
                }
                lft->lz = true;
                lft->upd = add(lft->upd, upd);
            }
            if (rgt != NULL) {
                if (br != -1) {
                    rgt->bv = bv;
                    rgt->br = br;
                    rgt->upd = NOL;
                }
                rgt->lz = true;
                rgt->upd = add(rgt->upd, upd);
            }
            val = add(val, make_pair(n*upd.first, n*upd.second));
            lz = false;
            br = -1;
            bv = NOL;
            upd = NOL;
        }
    }
    pair<int,int> Q(int ll, int rr)
    {
        Lz();
        if (ll <= l && r <= rr) return val;
        else if (r < ll || l > rr) return NOL;
        else {
            pair<int,int> lv = lft->Q(ll, rr), rv = rgt->Q(ll, rr);
            return add(lv, rv);
        }
    }
    void U(int ll, int rr, pair<int,int> v) {
        Lz();
        if (ll <= l && r <= rr) {
            upd = add(upd, v);
            lz = true;
            Lz();
        }
        else if (r < ll || l > rr) return;
        else {
            lft->U(ll, rr, v);
            rgt->U(ll, rr, v);
            val = add(lft->val, rgt->val);
        }
    }
    void U(int ll, int rr, pair<int,int> v, int t) {
        Lz();
        if (ll <= l && r <= rr) {
            // for lazy
            bv = v;
            br = t;
            lz = true;
            upd = NOL;
            Lz();
        }
        else if (r < ll || l > rr) return;
        else {
            lft->U(ll, rr, v, t);
            rgt->U(ll, rr, v, t);
            val = add(lft->val, rgt->val);
        }
    }
    ~SegTree()
    {
        if (lft != NULL) delete lft;
        if (rgt != NULL) delete rgt;
    }
};
int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<int> v;
        getr[0] = NOL;
        for (int i = 1; i <= n; ++i) {
            getr[i] = add(getr[i-1], get(i));
        }
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        SegTree root(0, n-1, v);
        long long ans = 0;
        while (q--) {
            int t;
            scanf("%d", &t);
            if (t == 1) {
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                --l, --r;
                root.U(l, r, get(x));
            }
            if (t == 2) {
                int l, r, y;
                scanf("%d%d%d", &l, &r, &y);
                --l, --r;
                root.U(l, r, get(y), l);
            }
            if (t == 3) {
                int l, r;
                scanf("%d%d", &l, &r);
                --l, --r;
                pair<int,int> v = root.Q(l, r);
                ans += min(v.first, v.second);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
