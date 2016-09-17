#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 1000000
int oxy[MAXN+5], nit[MAXN+5], w[MAXN+5];
int dp[80][80];

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int ox, ni;
		scanf("%d%d", &ox, &ni);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &oxy[i], &nit[i], &w[i]);
		}
		for (int i = 0; i <= ox; ++i) for (int j = 0; j <= ni; ++j)
			dp[i][j] = INF;

		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = ox; j >= 0; --j) {
				for (int k = ni; k >= 0; --k) {
					// take
					dp[j][k] = min(dp[j][k], dp[max(j-oxy[i], 0)][max(k-nit[i], 0)] + w[i]);
				}
			}
		}
		printf("%d\n", dp[ox][ni]);

	}
}
