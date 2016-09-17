#include <bits/stdc++.h>

using namespace std;

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		string s;
		cin >> s;
		bool not_started = true;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (s[i] == '0' && not_started) {
					continue;
				}
				printf("%c", s[i]);
				not_started = false;
			}
		}
		if (not_started) printf("0");
		puts("");
	}
}
