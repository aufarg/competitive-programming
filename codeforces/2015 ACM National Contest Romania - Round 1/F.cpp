#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

struct SegTree
{
    int ll, rr;
    int v;
    SegTree *lft, *rgt;

    stack<int> kup, vup, curv;
    SegTree(int l, int r)
    {
        ll = l, rr = r; curv.push(INF);
        if (l == r) lft = rgt = NULL;
        else {
            int mid = (l+r)/2;
            lft = new SegTree(l, mid);
            rgt = new SegTree(mid+1, r);
        }
    }

    void update(int l, int r, int nv, int kid)
    {
        printf("%d %d %d %d\n", ll, rr, nv, kid);
        if (r < ll || l > rr) return;
        else if (l <= ll && rr <= r) {
            kup.push(kid);
            vup.push(nv);
            curv.push(min(curv.top(), nv));
        }
        else {
            lft->update(l, r, nv, kid);
            rgt->update(l, r, nv, kid);
        }
    }

    int query(int x, int kid)
    {
        printf("%d %d %d %d\n", ll, rr, x, kid);
        if (x < ll | x > rr) return INF;
        else {
            while (!kup.empty() && kup.top() >= kid) {
                kup.pop();
                vup.pop();
                curv.pop();
            }
            if (lft != NULL) {
                while (!lft->kup.empty() && lft->kup.top() >= kid) {
                    lft->kup.pop();
                    lft->vup.pop();
                    lft->curv.pop();
                }
                while (!kup.empty() && !lft->kup.empty() && lft->kup.top ()){
                    lft->kup.push(kup.top());
                    lft->vup.push(vup.top());
                    lft->curv.push(min(lft->curv.top(), vup.top()));
                }
            }
            if (lft != NULL) {
                while (!rgt->kup.empty() && rgt->kup.top() >= kid) {
                    rgt->kup.pop();
                    rgt->vup.pop();
                    rgt->curv.pop();
                }
                if (lft != NULL) {
                    rgt->kup.push(kup.top());
                    rgt->vup.push(vup.top());
                    rgt->curv.push(min(rgt->curv.top(), vup.top()));
                }
            }
            if (ll != x || rr != x) return min(lft->query(x, kid), rgt->query(x, kid));
            else return curv.top();
        }
    }

};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    SegTree *root = new SegTree(1, n);
    int k = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        switch (s[0]) {
            case 'I':
                {
                    int x, y, z;
                    scanf("%d%d%d", &x, &y, &z);
                    root->update(x, y, z, ++k);
                    break;
                }
            case 'E':
                {
                    --k;
                    break;
                }
            case 'R':
                {
                    int x;
                    scanf("%d", &x);
                    printf("%d\n", root->query(x, k));
                    break;
                }
        }
    }
    return 0;
}
