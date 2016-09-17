#include <bits/stdc++.h>

using namespace std;

int g(int n, long long k) {
	if (n == 1) return 1;
	int par = g(n-1, k/2);
	return (par+k%2)%2;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		long long k;
		scanf("%d%lld", &n, &k);
		int ans = g(n,k-1);
		puts((ans) ? "Male" : "Female");
	}
	return 0;
}
