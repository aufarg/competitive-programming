#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define MAXN 3000

long long sum[MAXN+5];
int dp[MAXN+5][MAXN+5];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        sum[i] = sum[i-1] + a;
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dp[i][j] = -INF;
    for (int i = 1; i <= n; ++i) dp[1][i] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int best = -INF;
        for (int j = i; j <= n; ++j) {
            best = max(best, dp[i][j]);
            long long s = sum[j]-sum[i-1];
            int idx = lower_bound(sum+j+1, sum+n+1, s+sum[j])-sum;
            dp[j+1][idx] = max(dp[j+1][idx], best+1);
            ans = max(ans, dp[j+1][idx]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
