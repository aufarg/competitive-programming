#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int dp[MAXN+5][MAXN+5][2];

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int itc, n, k;
		scanf("%d%d%d", &itc, &n, &k);

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]);
				dp[i][j][1] = (dp[i-1][j-1][1] + dp[i-1][j][0]);
			}
		}

		printf("%d %d\n", itc, dp[n][k][0] + dp[n][k][1]);
	}
	return 0;
}
