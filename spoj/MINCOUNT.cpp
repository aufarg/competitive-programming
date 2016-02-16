#include <cstdio>

typedef long long ll;

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		ll n;
		scanf("%lld", &n);
		if (n == 0) {
			puts("0");
		}
		else {
			ll h = (n-1)/2;
			ll ans = h*(h+1) + ((n%2) ? 0 : 1);
			printf("%lld\n", ans);
		}
	}
}
