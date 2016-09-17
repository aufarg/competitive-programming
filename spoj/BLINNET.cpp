#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
int main() {
	int ntc;
	scanf("%d", &ntc);

	while (ntc--) {
		int n;
		vector<int> edge[MAXN+5], cost[MAXN+5];
		scanf("%d", &n);
		priority_queue<pair<int,int> > pq;
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int v, c;
				scanf("%d%d", &v, &c);
				edge[i].push_back(v);
				cost[i].push_back(c);
				if (i == 1) {
					pq.push(make_pair(-c, v));
				}
			}
		}
		int tr[MAXN+5] = {0};
		tr[1] = 1;
		unsigned ans = 0;
		while (!pq.empty()) {
			int v = pq.top().second;
			int c = -pq.top().first;
			pq.pop();
			if (tr[v]) continue;
			tr[v] = 1;
			ans += c;
			for (int j = 0; j < (int)edge[v].size(); ++j) {
				int u = edge[v][j];
				int l = cost[v][j];
				if (!tr[u]) 
					pq.push(make_pair(-l, u));
			}
		}
		printf("%u\n", ans);
	}
	return 0;
}
