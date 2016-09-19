#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009
#define MAXN 100000

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		scanf("%d", &n);
		int vis[MAXN+5];
		int a[MAXN+5];
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		long long ans = 1;
		int step = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == i || vis[i]) continue;
			int p = i;
			int cnt = 0;
			while (!vis[p]) {
				++cnt;
				vis[p] = 1;
				p = a[p];
			}
			assert(cnt > 1);
			printf("%d ", cnt);
		}
		puts("");
	}
}
