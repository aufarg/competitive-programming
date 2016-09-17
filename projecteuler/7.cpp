#include <bits/stdc++.h>

#define MAXV 1000000

int prime[MAXV+5];

int main() {
	for (int i = 2; i <= MAXV; ++i) prime[i] = 1;
	for (int i = 2; i*i <= MAXV; ++i) {
		if (prime[i]) {
			int t = i*i;
			while (t <= MAXV) {
				prime[t] = 0;
				t += i;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= MAXV; ++i) {
		if (!prime[i]) continue;
		++cnt;
		if (cnt == 10001) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", cnt);
}
