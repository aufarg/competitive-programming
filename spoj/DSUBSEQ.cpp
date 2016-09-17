#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define MAXN 100000
int n;
char s[MAXN+5];
int sum[30];

inline int add(int a, int b) {
	return (a+b)%MOD;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		scanf("%s", s);
		n = strlen(s);
		memset(sum, 0, sizeof(sum));
		int tsum = 0;
		for (int i = 0; i < n; ++i) {
			int cv = s[i]-'A';
			int lsum = sum[cv];
			sum[cv] = tsum + 1;
			tsum = add(tsum,(sum[cv] - lsum + MOD) % MOD);
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i) ans = add(ans,sum[i]);
		printf("%d\n", ans+1);
	}
	return 0;
}
