#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
int arr[MAXN+5];

int main() {
	int n;
	scanf("%d", &n);
	int zero = 0;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		if (arr[i] == 0) zero++;
	}

	int ans = zero;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int a = arr[i], b = arr[j];
			if (a == 0 && b == 0) continue;
			vector<int> nums;
			nums.push_back(a);
			nums.push_back(b);
			--cnt[a];
			--cnt[b];
			int tans = 2;
			while (cnt.find(a+b) != cnt.end() && cnt[a+b] > 0) {
				int c = a+b;
				a = b; b = c;
				nums.push_back(c);
				--cnt[c];
				++tans;
			}
			ans = max(ans, tans);
			for (int k = 0; k < (int)nums.size(); ++k)
				++cnt[nums[k]];
		}
	}
	printf("%d\n", ans);

	return 0;
}
