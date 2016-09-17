#include <bits/stdc++.h>

using namespace std;

#define MAXV 4000000

int main() {
	int a = 1, b = 2;
	long long ans = b;
	while (a+b <= MAXV) {
		int c = a+b;
		a = b; b = c;
		if (b % 2 == 0) ans += b;
	}
	printf("%lld\n", ans);
	return 0;
}
