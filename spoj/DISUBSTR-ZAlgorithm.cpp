#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int z[MAXN+5][MAXN+5], zm[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string ss;
        cin >> ss;

        long long ans = 0;
        memset(z, 0, sizeof(z));
        memset(zm, 0, sizeof(zm));
        for (int j = 0; j < ss.size(); ++j) {
            string s = ss.substr(j, ss.size()-j);
            int l = 0, r = 0;
            for (int i = 1; i < s.size(); ++i) {
                if (i > r) {
                    l = r = i;
                    while (r < s.size() && s[r] == s[r-l]) ++r;
                    z[j][i] = r-l; --r;
                }
                else {
                    int k = i-l;
                    if (z[j][k] < r-i+1) z[j][i] = z[j][k];
                    else {
                        l = i;
                        while (r < s.size() && s[r] == s[r-l]) ++r;
                        z[j][i] = r-l; --r;
                    }
                }
            }
        }
        for (int j = 0; j < ss.size(); ++j) {
            for (int i = 0; i+j < ss.size(); ++i) {
                zm[j+i] = max(zm[j+i], z[j][i]);
            }
        }
        for (int i = 0; i < ss.size(); ++i) {
            int len = ss.size()-i;
            ans += len-zm[i];
        }
        printf("%lld\n", ans);

    }
    return 0;
}
