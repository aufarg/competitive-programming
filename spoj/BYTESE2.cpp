#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second
#define MAXN 100

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 0; itc < ntc; ++itc) {
		int n;
		scanf("%d", &n);
		pii p[2*MAXN+5];
		for (int i = 0; i < 2*n; ++i) {
			scanf("%d", &p[i].F);
			p[i].S = i / 2;
		}
		sort(p, p+2*n);
		set<int> intv;
		int ans = 0;
		for (int i = 0; i < 2*n; ++i) {
			if (intv.find(p[i].S) != intv.end()) {
				intv.erase(p[i].S);
			}
			else {
				intv.insert(p[i].S);
				ans = max(ans, (int)intv.size());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
