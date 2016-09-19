#include <bits/stdc++.h>

using namespace std;

#define MAXN 200

int main() {
	int n, m;
	while (scanf("%d", &n), n != 0) {
		scanf("%d", &m);
		double adj[MAXN+5][MAXN+5];
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) adj[i][j] = 0.0;
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a][b] = adj[b][a] = (double)c/100.0;
			assert(adj[a][b] <= 1.0);
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					adj[i][j] = max(adj[i][j], adj[i][k] * adj[k][j]);

		printf("%.6lf percent\n", adj[1][n] * 100);
	}
	return 0;
}
