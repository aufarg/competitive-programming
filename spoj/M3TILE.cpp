#include <bits/stdc++.h>
#include <cassert>

using namespace std;

#define MAXN 30
int n;
int vis[MAXN+5][30];
long long memo[MAXN+5][30];

long long dp(int cur, int mask) {
	long long &ret = memo[cur][mask];
	if (cur == 0) return (mask == 0) ? 1 : 0;
	if (vis[cur][mask]) return ret;
	ret = 0;
	if (mask == 0) ret = dp(cur-1, 1) + dp(cur-1, 4) + dp(cur-1, 7);
	if (mask == 1) ret = dp(cur-1, 0) + dp(cur-1, 6);
	if (mask == 4) ret = dp(cur-1, 0) + dp(cur-1, 3);
	if (mask == 7) ret = dp(cur-1, 0);
	if (mask == 6) ret = dp(cur-1, 1);
	if (mask == 3) ret = dp(cur-1, 4);
	//assert(mask == 0 || mask == 1 || mask == 4 || mask == 7);
	vis[cur][mask] = 1;
	return ret;
}

int main() {
	while (scanf("%d", &n), n != -1) {
		printf("%lld\n", dp(n, 0));
	}
}
