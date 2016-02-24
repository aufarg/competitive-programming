#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
int a[MAXN+5][MAXN+5];

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				int found = 0;
				for (int k = 0; k < n; ++k) {
					if (i == j) continue;
					if (i == k || j == k) continue;
					if (a[i][k] + a[k][j] == a[i][j]) found = 1;
				}
				if (!found)
					printf("%d %d\n", i+1, j+1);
			}
		}
		if (ntc) puts("");
	}
}
