#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	vector<pii> p;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'C') {
				p.push_back(make_pair(i, j));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < p.size(); ++i) {
		for (int j = i+1; j < p.size(); ++j) {
			if (p[i].first == p[j].first || p[i].second == p[j].second) ++ans;
		}
	}
	printf("%d\n", ans);
}
