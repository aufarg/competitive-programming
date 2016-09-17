#include <bits/stdc++.h>

using namespace std;

bool check(long long k) {
	bool prime = true;
	for (long long j = 2; j*j <= k; ++j)
		if (k%j==0) prime = false;
	return prime;
}

int main() {
	const long long n = 600851475143;
	for (long long i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			long long k = n/i;
			if (check(k)) printf("%lld\n", k);
		}
	}
	for (long long i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			long long k = i;
			if (check(k)) printf("%lld\n", k);
		}
	}
}
