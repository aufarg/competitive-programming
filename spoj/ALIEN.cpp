#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
int a[MAXN+5];

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n, b;
		scanf("%d%d", &n, &b);
		for (int i = 0; i < n; ++i) 
			scanf("%d", &a[i]);
		
		int p = 0, q = 0;
		int sum = 0;
		int ans = 0, cost = 0;
		while (p < n) {
			while (p < n && sum <= b) {
				if (ans == p-q) {
					cost = min(cost, sum);
				}
				if (ans < p-q) {
					ans = p-q;
					cost = sum;
				}
				sum += a[p];
				++p;
			}
			while (q < p && sum > b) {
				sum -= a[q];
				++q;
			}
		}
		while (q < p) {
			if (ans == p-q) {
				cost = min(cost, sum);
			}
			if (ans < p-q) {
				ans = p-q;
				cost = sum;
			}
			sum -= a[q];
			++q;
		}
		printf("%d %d\n", cost, ans);
	}
	return 0;
}
