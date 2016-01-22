#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

typedef pair<int,int> pii;

#define MAXN 10000

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		string s;
		cin >> s;
		s += s;
		int fail[2*MAXN+5];
		memset(fail, -1, sizeof(fail));
		int n = (int)s.size();
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			int j = fail[i-ans-1];
			while (j != -1 && s[i] != s[ans+j+1]) {
				if (s[i] < s[ans+j+1]) ans = i-j-1;
				j = fail[j];
			}

			if (j == -1 && s[i] != s[ans+j+1]) {
				if (s[i] < s[ans+j+1]) ans = i;
				fail[i-ans] = -1;
			}
			else {
				fail[i-ans] = j+1;
			}
		}
		printf("%d\n", ans + 1);

	}
	return 0;
}
