#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	return (b) ? gcd(b, a % b) : a;
}
int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		long long n;
		scanf("%lld", &n);
		long long t = n / 2;
		while (gcd(t,n) > 1) --t;
		printf("%lld\n", t);
	}
}
