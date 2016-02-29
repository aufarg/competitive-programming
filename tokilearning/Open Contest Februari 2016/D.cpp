#include <bits/stdc++.h>

using namespace std;

#define MAXV 10000000
int flag[MAXV+5];

int main() {
	for (int i = 2; i <= MAXV; ++i) flag[i] = 1;
	for (int i = 2; i*i <= MAXV; ++i) {
		if (flag[i] == 1) {
			int t = i*i;
			while (t <= MAXV) {
				flag[t] = i;
				t += i;
			}
		}
	}
	for (int i = 1; i <= MAXV; ++i) 
		if (flag[i] == 1) flag[i] = i;

	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int tmp = n;
		int fact = 0;
		while (tmp > 1) {
			fact++;
			tmp /= flag[tmp];
		}
		if (fact == k) puts("Ya");
		else puts("Tidak");
	}
}
