#include <bits/stdc++.h>

using namespace std;

#define MAXV 35000
#define MAXN 3000
vector<int> g;
int flag[MAXV+5];
int nxt[MAXV+5];
int main() {
	int n;
	memset(flag, 1, sizeof(flag));
	for (int i = 2; i <= MAXV; ++i) nxt[i] = i+1;
	for (int i = 2; i <= MAXV; ++i) {
		if (flag[i]) {
			int cnt = 0;
			int t = nxt[i];
			int p = i;
			while (t <= MAXV) {
				++cnt;
				if (cnt % i == 0) {
					nxt[p] = nxt[t];
					flag[t] = 0;
				}
				p = t;
				t = nxt[t];
			}
			g.push_back(i);
		}
	}
	assert(g.size() >= MAXN);
	while (scanf("%d", &n), n != 0) {
		printf("%d\n", g[n-1]);
	}
	return 0;
}
