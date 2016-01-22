#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		ll n;
		cin >> n;
		--n;
		ll ans = 0;
		ll p3 = n/3, p5 = n/5, p15 = n/15;
		ans += 3 * (p3 * (p3+1) / 2) + 5 * (p5 * (p5+1) / 2) - 15 * (p15 * (p15+1) / 2);
		cout << ans << endl;
	}
	return 0;
}

