#include <bits/stdc++.h>

using namespace std;

#define MAXN 20
int n;
vector<int> pref[MAXN+5];
long long dp[MAXN+5][(1<<MAXN)+5];
long long vis[MAXN+5][(1<<MAXN)+5];

long long work1(int p, int mask) {
	if (p == n/2) return 1;
	long long &ret = dp[p][mask];
	if (vis[p][mask]) return ret;
	vis[p][mask] = 1;
	ret = 0;
	for (int i = 0; i < (int)pref[p].size(); ++i)
		if ((mask & 1<<pref[p][i]) == 0)
			ret += work1(p+1, mask & ~(1LL<<pref[p][i]));
	return ret;
}

long long work2(int p, int mask) {
	if (p == n) return 1;
	long long &ret = dp[p][mask];
	if (vis[p][mask]) return ret;
	vis[p][mask] = 1;
	ret = 0;
	for (int i = 0; i < (int)pref[p].size(); ++i)
		if ((mask & 1<<pref[p][i]) == 0)
			ret += work2(p+1, mask & ~(1LL<<pref[p][i]));
	return ret;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			pref[i].clear();
			for (int j = 0; j < n; ++j) {
				int a;
				scanf("%d", &a);
				if (a)
					pref[i].push_back(j);
			}
		}
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		long long ans = 0;
		for (int i = 0; i < (1LL<<n); ++i) {
			int v = (1LL<<n);
		}
	}
	return 0;
}

