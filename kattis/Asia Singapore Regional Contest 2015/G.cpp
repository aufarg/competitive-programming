#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define MAXN 3000
typedef long long ll;
typedef pair<long long, long long> pll;

int n;
ll a[MAXN+5];
ll sum[MAXN+5];
int vis[MAXN+5];
vector<ll> th[MAXN+5];
vector<ll> memo[MAXN+5];

#define INF 3000000000000LL

ll dp(int pos, ll threshold) {
	if (pos >= n) return 0;
	if (vis[pos]) {
		int idx = lower_bound(th[pos].begin(), th[pos].end(), threshold) - th[pos].begin();
		if (idx < n) 
			return memo[pos][idx];
		else
			return -INF;
	}
	vis[pos] = 1; 
	for (int i = pos; i < n; ++i) {
		ll ret = dp(i+1, sum[i]-sum[pos-1]) + 1;
		th[pos].push_back(sum[i] - sum[pos-1]);
		memo[pos].push_back(ret);
	}
	for (int i = memo[pos].size() - 2; i >= 0; --i) {
		memo[pos][i] = max(memo[pos][i], memo[pos][i+1]); 
	}
	int idx = lower_bound(th[pos].begin(), th[pos].end(), threshold) - th[pos].begin();
	if (idx < n)
		return memo[pos][idx];
	else
		return -INF;
}

int main() {
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum[i] = a[i];
		if (i) sum[i] += sum[i-1];
	}

	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp(i+1, sum[i]));
	}

	cout << ans+1 << endl;

	return 0;
}
