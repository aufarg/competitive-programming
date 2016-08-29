#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000LL
#define MAXN 10000000

long long dp[2*MAXN+5];

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i <= n; ++i) dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i%2==0) {
            dp[i] = min(dp[i-1]+x, dp[i/2]+y);
        }
        else {
            dp[i] = min(dp[i-1]+x, min(dp[(i-1)/2],dp[(i+1)/2])+x+y);
        }
    }

    cout << dp[n] << endl;
}
