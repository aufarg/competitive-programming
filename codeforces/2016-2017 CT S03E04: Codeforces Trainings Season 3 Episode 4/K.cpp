#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define INF 1e9

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        int xl, yl;
        scanf("%d%d", &xl, &yl);
        vector<pair<double, double> > ints;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x, y, u, v;
            scanf("%d%d%d%d", &x, &y, &u, &v);
            double x1 = (double)(x-xl)*(double)(yl)/(double)(yl-y);
            double x2 = (double)(u-xl)*(double)(yl)/(double)(yl-v);
            double l, r;
            if (x1+EPS > x2) r = x1, l = x2;
            else l = x1, r = x2;
            ints.push_back(make_pair(l, r));
        }
        sort(ints.begin(), ints.end());
        double rmost = -INF;
        for (int i = 0; i < n; ++i) {
            if (rmost < ints[i].first) {
                ++ans;
            }
            rmost = max(rmost, ints[i].second);
        }
        printf("%d\n", ans);
    }
    return 0;
}
