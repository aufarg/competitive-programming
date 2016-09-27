#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    map<int, vector<pair<int,int> > > gg;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int r, c1, c2;
        scanf("%d%d%d", &r, &c1, &c2);
        gg[r].push_back(make_pair(c1, 0));
        gg[r].push_back(make_pair(c2, 1));
    }
    long long ans = (long long)n*(long long)m;
    for (__typeof(gg.begin()) it = gg.begin(); it != gg.end(); ++it) {
        vector<pair<int, int> > v = it->second;
        sort(v.begin(), v.end());
        int s = 0, begin = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].second == 0) {
                if (s == 0) begin = max(begin+1, v[i].first);
                ++s;
            }
            else {
                --s;
                if (s == 0) {
                    ans -= (v[i].first-begin+1);
                    begin = v[i].first;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
