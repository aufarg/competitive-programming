#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 20
long long dp[(1<<MAXN)+5];
int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		scanf("%d", &n);
		int a[MAXN+5][MAXN+5];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1LL;
		for (int bit = 0; bit < (1LL<<n); ++bit) {
			int bc = __builtin_popcount(bit);
			for (int i = 0; i < n; ++i) {
				if (a[bc][i] && (bit & (1<<i)) == 0)
					dp[bit | (1<<i)] += dp[bit];
			}
		}
		printf("%lld\n", dp[(1<<n)-1]);
	}
	return 0;
}
