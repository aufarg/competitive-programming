#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int tr = 0;

	vector<int> ans;
	for (int i = 1; tr <= n; ++i) {
		int tmp = i;
		while (tmp % 5 == 0) ++tr, tmp /= 5;
		if (tr == n) {
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}
