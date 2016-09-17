#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		string s;
		cin >> s;
		int n = s.size();
		deque<char> ans;
		for (int i = 0; i < n; ++i) {
			if (ans.empty() || ans.front() <= s[i]) ans.push_front(s[i]);
			else ans.push_back(s[i]);
		}
		printf("Case #%d: ", itc);
		for (int i = 0; i < n; ++i) {
			printf("%c", ans.front());
			ans.pop_front();
		}
		printf("\n");
	}
	return 0;
}
