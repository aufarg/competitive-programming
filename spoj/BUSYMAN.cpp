#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

#define MAXN 100000
#define F first
#define S second

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n;
		pii p[MAXN+5];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &p[i].S, &p[i].F);
		}

		sort(p, p+n);
		int ans = 0;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (cur <= p[i].S) {
				++ans;
				cur = p[i].F;
			}
		}

		printf("%d\n", ans);
	}
}
