#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

#define MAXN 10000

int main() {
	int prime[MAXN+5];
	int factor[MAXN+5];
	memset(prime, -1, sizeof(prime));
	memset(factor, 0, sizeof(factor));

	prime[0] = prime[1] = 0;
	for (int i = 2; i <= MAXN; ++i) factor[i] = i;
	for (int i = 2; i * i <= MAXN; ++i) {
		if (!prime[i]) continue;
		for (int t = i * i; t <= MAXN; t += i) {
			prime[t] = 0;
			factor[t] = i;
		}
	}

	int ans[MAXN+5];
	int ansc = 0;
	for (int i = 2; i <= MAXN; ++i) {
		if (prime[i]) continue;
		set<int> s;
		int tmp = i;
		while (tmp > 1) {
			s.insert(factor[tmp]);
			tmp /= factor[tmp];
		}

		if (s.size() < 3) continue;
		++ansc;
		ans[ansc] = i;
	}

	int ntc;
	scanf("%d", &ntc);
	for (int itc = 0; itc < ntc; ++itc) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	
	return 0;
}
