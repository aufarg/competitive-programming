#include <bits/stdc++.h>

using namespace std;

int main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		string s[12];
		for (int i = 0; i < 10; ++i) cin >> s[i];
		bool ok = false;
		for (int i = 0; !ok && i < 10; ++i)
			for (int j = 0; !ok && j < 10; ++j) {
				if (i == j) continue;
				bool can = true;
				for (int ii = 0; !ok && ii < s[i].size(); ++ii) {
					can = true;
					for (int k = 0; ii+k < s[i].size() && k < s[j].size(); ++k) {
						if (s[i][ii+k] != s[j][k]) can = false;
					}
					if (can) {
						string ans = "";
						for (int l = 0; l < ii; ++l) ans += s[i][l];
						ans += s[j];
						for (int k = 0; k < 10; ++k) {
							if (k != i && k != j) {
								ans += s[k];
							}
						}
						int len = ans.size();
						cout << ans;
						for (int k = 0; k < 39-len; ++k) {
							cout << "A";
						}
						cout << endl;
						ok = true;
					}
				}
			}
		assert(ok);
	}
}
