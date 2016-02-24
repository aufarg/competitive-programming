#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAXB 1000
char buf[MAXB+5];
int adj[30][30];
int vis[30];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < 26; ++i) {
		if (adj[v][i]) dfs(i);
	}
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		scanf("%d", &n);
		int in[30];
		int out[30];
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		memset(adj, 0, sizeof(adj));
		memset(vis, 0, sizeof(vis));
		int start = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			int a = buf[0]-'a', b = buf[strlen(buf)-1]-'a';
			++out[a];
			++in[b];
			adj[a][b] = adj[b][a] = 1;
			start = a;
		}
		int b_in = 1, b_out = 1;
		int can = 1;
		for (int i = 0; i < 26; ++i) {
			int diff = out[i] - in[i];
			if (out[i]+in[i] > 0) {
				if (diff == 0) {}
				else if (diff == 1) {
					if (!b_in) can = 0;
					b_in = 0;
				}
				else if (diff == -1) {
					if (!b_out) can = 0;
					b_out = 0;
				}
				else can = 0;
			}
		}
		dfs(start);
		for (int i = 0; i < 26; ++i) {
			if (out[i]+in[i] > 0 && !vis[i]) {
				can = 0;
			}
		}
		puts((can) ? "Ordering is possible." : "The door cannot be opened.");

	}
	return 0;
}
