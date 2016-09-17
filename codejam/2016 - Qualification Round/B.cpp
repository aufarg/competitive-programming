#include <bits/stdc++.h>

using namespace std;

int unhappy(string s)
{
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] == '-') return 1;
	return 0;
}

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		string s;
		cin >> s;
		int ans = 0;
		while (unhappy(s)) {
			int l = 0;
			int r = (int)s.size()-1;
			while (s[r] == '+') --r;
			if (s[l] == '+') {
				while (s[l] == '+') ++l;
				for (int i = 0; i < l; ++i)
					s[i] = '-';
				++ans;
			}
			if (unhappy(s)) {
				for (int i = 0; i <= r; ++i) {
					if (s[i] == '-') s[i] = '+';
					else s[i] = '-';
				}
				reverse(s.begin(), s.begin()+r+1);
				++ans;
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	return 0;
}
