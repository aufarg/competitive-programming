#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,x,y;
    scanf("%d%d%d%d", &n, &k, &x, &y);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i <= k) ans += x;
        else ans += y;
    }
    printf("%lld\n", ans);
    return 0;
}
