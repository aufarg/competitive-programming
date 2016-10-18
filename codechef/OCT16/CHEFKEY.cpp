#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n, m, c;
        scanf("%d%d%d", &n, &m, &c);
        int ans = 0;
        for (int i = 1; i*i <= c; ++i) {
            if (c%i) continue;
            int a = i, b = c/i;
            if (a != b) {
                if (a <= n && b <= m) ++ans;
                if (a <= m && b <= n) ++ans;
            }
            else if (a <= n && b <= m) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
