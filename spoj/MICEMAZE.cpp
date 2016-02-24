#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define INF 1000000000
int dist[MAXN+5][MAXN+5];

int main() {
	int n, e, t, m;
	scanf("%d%d%d%d", &n, &e, &t, &m);
	--e;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			dist[i][j] = INF;
		}
	for (int i = 0; i < n; ++i) dist[i][i] = 0;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		dist[a][b] = c;
	}

	for (int k = 0; k < n; ++k) 
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[i][e] <= t) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}
