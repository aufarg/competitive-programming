#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 20
int n, k;
int memo[2*MAXN+5][2*MAXN+5];
int vis[2*MAXN+5][2*MAXN+5];
int op[2*MAXN+5];

int dp(int pos, int brackets) {
	if (brackets < 0) return 0;
	if (pos > 2*n) {
		return (brackets == 0);
	}
	int &ret = memo[pos][brackets];
	if (vis[pos][brackets]) return ret;
	vis[pos][brackets] = 1;
	ret = dp(pos+1, brackets+1);
	if (!op[pos]) ret += dp(pos+1, brackets-1);
	return ret;
}
int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		memset(vis, 0, sizeof(vis));
		memset(op, 0, sizeof(op));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; ++i) {
			int a;
			scanf("%d", &a);
			op[a] = 1;
		}
		printf("%d\n", dp(1,0));
	}
	return 0;
}
