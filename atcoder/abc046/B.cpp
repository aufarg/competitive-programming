#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    long long ans = k;
    for (int i = 1; i < n; ++i) ans *= (k-1);
    printf("%lld\n", ans);
}
