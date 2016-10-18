#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
long long a[MAXN+5];
long long ans[MAXN+5];
int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> cnt, exact;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = n-1; i >= 0; --i) exact[cnt[a[i]]] = i;
    int q;
    scanf("%d", &q);
    vector<pair<long long, pair<int, int> > > qm;
    for (int qq = 0; qq < q; ++qq) {
        int t; long long f;
        scanf("%d%lld", &t, &f);
        qm.push_back(make_pair(f, make_pair(t, qq)));
    }
    sort(qm.begin(), qm.end());
    int j = 0;
    int cur = 0;
    for (int i = 0; i < qm.size(); ++i) {
        long long f = qm[i].first;
        int t = qm[i].second.first;
        int idx = qm[i].second.second;
        if (t) {
            if (exact.find(f) != exact.end()) ans[idx] = a[exact[f]];
            else ans[idx] = 0;
        }
        else {
            while (j < n && cur < f) {
                cur = cnt[a[j]];
                ++j;
            }
            if (cur < f) ans[idx] = 0;
            else ans[idx] = a[j-1];
        }
    }
    for (int qq = 0; qq < q; ++qq) {
        printf("%lld\n", ans[qq]);
    }
    return 0;
}
