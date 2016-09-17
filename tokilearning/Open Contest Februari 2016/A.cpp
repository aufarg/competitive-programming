#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
int a[MAXN+5];

#define INF 1000000000
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	sort(a, a+n);
	int ans = INF;
	for (int i = 0; i+k-1 < n; ++i) {
		ans = min(ans, a[i+k-1]-a[i]);
	}
	if (k == 1) ans = 0;
	printf("%d\n", ans);
	return 0;
}
