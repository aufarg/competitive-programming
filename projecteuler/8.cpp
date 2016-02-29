#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main() {
	freopen("8.in", "r", stdin);
	string s;
	cin >> s;
	for (int i = 0; i < 1000; ++i) {
		int v = s[i]-'0';
		a[i] = v;
	}
	long long ans = 0;
	for (int i = 0; i < 1000; ++i) {
		long long v = 1;
		for (int j = 0; j < 13; ++j) {
			v *= a[i+j];
		}
		ans = max(ans, v);
	}
	printf("%lld\n", ans);
}
