#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	return (b) ? gcd(b, a%b) : a;
}

int main() {
	long long n = 1;
	for (int i = 2; i <= 20; ++i) {
		n = (n*i)/gcd(n,i);
	}
	printf("%lld\n", n);

	return 0;
}
