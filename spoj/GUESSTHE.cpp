#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return (b) ? gcd(b, a%b) : a;
}
int main() {
	string s;
	while (cin >> s) {
		if (s == "*") break;
		int ans = 1;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == 'Y') {
				int v = i+1;
				ans = v / gcd(ans, v) * ans;
			}
		}
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == 'N') {
				int v = i+1;
				if (ans % v == 0) {
					ans = -1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}
