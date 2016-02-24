#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	return (b) ? gcd(b, a % b) : a;
}

int main() {
	int w, h;
	while (scanf("%d%d", &w, &h), w != 0 && h != 0) {
		long long g = gcd(w, h);
		long long ww = w/g, hh = h/g;
		printf("%lld\n", ww * hh);
	}
	return 0;
}
