#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
long long a[MAXN+5];

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			long long cnt = n-i;
			ans += sum-cnt*a[i];
			sum -= a[i];
		}
		printf("%lld\n", ans);
	}
}












