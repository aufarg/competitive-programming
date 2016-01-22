#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 50
#define MAXM 50

int n, m;
int memo[MAXN+5][MAXM+5][30];
int vis[MAXN+5][MAXM+5][30];
char a[MAXN+5][MAXM+5];

int dp(int r, int c, int v) {
	//printf("%d %d %d\n", r, c, v);
	if (r < 0 || c < 0 || r >= n || c >= m) return 0;
	if (a[r][c]-'A' != v) return 0;

	int &ret = memo[r][c][v];
	if (vis[r][c][v]) return ret;
	vis[r][c][v] = 1;
	for (int i = 0; i < 8; ++i) {
		static int dr[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
		static int dc[] = { -1, 0, 1, -1, 0, 1, 1, -1 };
		ret = max(ret, 1 + dp(r + dr[i], c + dc[i], a[r][c]-'A'+1));
	}
	//printf("(%d,%d) %d = %d\n", r,c,v,ret);
	return ret;
}

int main() {
	int ntc = 0;
	while (scanf("%d%d", &n, &m), n != 0 || m != 0) {
		string s;
		getline(cin, s);
		memset(vis, 0, sizeof(vis));
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			for (int j = 0; j < m; ++j) {
				a[i][j] = s[j];
				//printf("%c", s[j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans = max(ans, dp(i,j,0));
			}
		}
		printf("Case %d: %d\n", ++ntc, ans);
	}

	return 0;
}
