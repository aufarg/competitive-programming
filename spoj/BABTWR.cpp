#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int h, w, l;
} dim;

bool cmp(const dim& a, const dim& b) {
	return a.w < b.w;
}

#define MAXN 1000
int dp[MAXN+5][MAXN+5];

int main() {
	int n;
	while (scanf("%d", &n), n != 0) {
		memset(dp, 0, sizeof(dp));
		vector<dim> blocks;
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			dim t1 = { a, b, c };
			dim t2 = { b, a, c };
			dim t3 = { c, a, b };
			dim t4 = { a, c, b };
			dim t5 = { b, c, a };
			dim t6 = { c, b, a };
			blocks.push_back(t1);
			blocks.push_back(t2);
			blocks.push_back(t3);
			blocks.push_back(t4);
			blocks.push_back(t5);
			blocks.push_back(t6);
		}
		sort(blocks.begin(), blocks.end(), cmp);
		
		n = blocks.size();
		dp[0][0] = blocks[0].h;
		for (int i = 1; i < n; ++i) {
			dp[i][i] = blocks[i].h;
			for (int j = 0; j <= i; ++j) {
				if (j < i) {
					dim a = blocks[j], b = blocks[i];
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
					if (a.w < b.w && a.l < b.l) {
						dp[i][i] = max(dp[i][i], dp[i][j]+b.h);
					}
				}
				else {
					dp[i][j] = max(dp[i][j], dp[i][j]);
				}

			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, dp[n-1][i]);

		printf("%d\n", ans);
	}
}
