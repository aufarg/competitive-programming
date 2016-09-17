#include <bits/stdc++.h>

using namespace std;

#define MAXV 2500
int cnt[MAXV+5];

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int n;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (int i = 0; i < 2*n-1; ++i) {
			for (int j = 0; j < n; ++j) {
				int v;
				scanf("%d", &v);
				cnt[v]++;
			}
		}
		printf("Case #%d: ", itc);
		int first = 1;
		for (int i = 0; i <= MAXV; ++i) {
			if (cnt[i] % 2) {
				if (!first) printf(" ");
				first = 0;
				printf("%d", i);
			}
		}
		puts("");
	}
	return 0;
}
