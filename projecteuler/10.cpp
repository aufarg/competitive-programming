#include <bits/stdc++.h>

using namespace std;

#define MAXV 2000000

int prime[MAXV+5];

int main() {
	for (int i = 2; i < MAXV; ++i) prime[i] = 1;
	for (int i = 2; i*i < MAXV; ++i) {
		if (prime[i]) {
			int t = i*i;
			while (t < MAXV) {
				prime[t] = 0;
				t += i;
			}
		}
	}
	long long ans = 0;
	for (long long i = 2; i < MAXV; ++i) {
		if (prime[i]) ans += i;
	}
	printf("%lld\n", ans);
	return 0;
}
