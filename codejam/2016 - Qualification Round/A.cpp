#include <bits/stdc++.h>

using namespace std;

int vis[15];

vector<int> rdg(long long n)
{
	vector<int> ret;
	while (n) {
		int d = n % 10;
		ret.push_back(d);
		n /= 10;
	}
	return ret;
}

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", itc);
		}
		else {
			memset(vis, 0, sizeof(vis));
			int cnt = 0;
			long long val = n;
			while (cnt < 10) {
				vector<int> digits = rdg(val);
				for (int i = 0; i < (int)digits.size(); ++i) {
					if (vis[digits[i]] == 0) {
						vis[digits[i]] = 1;
						++cnt;
					}
				}
				val += n;
			}
			printf("Case #%d: %lld\n", itc, val-n);
		}
	}
	return 0;
}
