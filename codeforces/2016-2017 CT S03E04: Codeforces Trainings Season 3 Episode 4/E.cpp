#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int a[MAXN+5], dp[MAXN+5][MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));

        for (int k = 1; k < n; k+=2) for (int i = 1; i+k <= n; ++i) {
            int j = i+k;
            dp[i][j] = max(dp[i][j], dp[i+1][j-1]+(a[i]==a[j]));
            for (int m = i; m+1 <= j; ++m) dp[i][j] = max(dp[i][j], (dp[i][m]+dp[m+1][j]));
        }
        printf("%d\n", dp[1][n]);

    }
    return 0;
}
