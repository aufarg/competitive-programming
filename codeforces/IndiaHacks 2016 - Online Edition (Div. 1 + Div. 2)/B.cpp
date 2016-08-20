#include <bits/stdc++.h>

using namespace std;

int n, q;
int vis[50][50];
int mem[50][50];
string s[50], t[50];

int dp(int p, int last) {
	if (p == 0) return !last;
	int &ret = mem[p][last];
	if (vis[p][last]) return ret;
	vis[p][last] = 1;
	for (int i = 0; i < 6; ++i) {
		for (int k = 0; k < 6; ++k) {
			for (int j = 0; j < q; ++j) {
				string ss = s[j], tt = t[j];
				if (ss[0]-'a' == last && ss[1]-'a' == i && tt[0]-'a' == k) {
					ret += dp(p-1, k);
				}
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		cin >> s[i] >> t[i];
	}
	int ans = 0;
	for (int i = 0; i < 6; ++i) {
		ans += dp(n-1, i);
	}
	printf("%d\n", ans);
	return 0;
}
