#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
vector<int> edge[MAXN+5];

int memo[MAXN+5][2];
int vis[MAXN+5][2];

int dp(int v, int last) {
	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}
