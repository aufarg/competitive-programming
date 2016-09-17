#include <bits/stdc++.h>

using namespace std;

#define MAXN 10
int grid[MAXN+5][MAXN+5];

int main() {
	int r,c,n,k;
	scanf("%d%d%d%d", &r, &c, &n, &k);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; -- b;
		grid[a][b] = 1;
	}
	int ans = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			for (int ii = i; ii < r; ++ii)
				for (int jj = j; jj < c; ++jj) {
					int sum = 0;
					for (int iii = i; iii <= ii; ++iii)
						for (int jjj = j; jjj <= jj; ++jjj) {
							sum += grid[iii][jjj];
						}
					if (sum >= k) ++ans;
				}
	printf("%d\n", ans);
	return 0;
}
