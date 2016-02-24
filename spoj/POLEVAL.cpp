#include <bits/stdc++.h>

#define MAXN 1000
int c[MAXN+5];

int main() {
	int n, ntc = 0;
	while (scanf("%d", &n), n != -1) {
		for (int i = 0; i <= n; ++i) {
			scanf("%d", &c[i]);
		}
		int k;
		scanf("%d", &k);
		printf("Case %d:\n", ++ntc);
		for (int i = 0; i < k; ++i) {
			int x;
			scanf("%d", &x);
			long long ret = 0;
			for (int j = 0; j <= n; ++j) {
				ret = ret * x + c[j];
			}
			printf("%lld\n", ret);
		}
	}
}
