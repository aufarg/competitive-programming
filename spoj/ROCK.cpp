#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
#define INF 1000

int memo[MAXN+5][MAXN+5];
int vis[MAXN+5][MAXN+5];
int a[MAXN+5];
int n;

int dp(int now, int last, int sum) {
	if (now >= n) {
		if (now == last) return 0;
		else return -INF;
	}
	int &ret = memo[now][last];
	if (vis[now][last]) return ret;
	// ambil terus
	ret = dp(now+1, last, sum + a[now+1]);
	
	// potong di sini
	ret = max(ret, dp(now+1, now+1, a[now+1]));
	// sell
	if (sum * 2 > (now-last+1)) {
		ret = max(ret, dp(now+1, now+1, a[now+1]) + now-last+1);
	}

	vis[now][last] = 1;
	return ret;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) a[i] = s[i]-'0';
		printf("%d\n", dp(0,0,a[0]));
	}
}
