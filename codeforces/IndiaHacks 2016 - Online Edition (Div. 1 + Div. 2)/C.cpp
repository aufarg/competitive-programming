#include <bits/stdc++.h>

using namespace std;

#define MAXN 150000

int n;
int ar[MAXN+5];
map<pair<int,int>, int> vis;
vector<int> prob;

int check(int i) {
	if (i < 0 || i >= n) return 1;
	if (i % 2) {
		int th = 0;
		if (i) th = max(ar[i-1], th);
		if (i<n-1) th = max(ar[i+1], th);
		if (ar[i] <= th) return 0;
	}
	else {
		int th = MAXN;
		if (i) th = min(ar[i-1], th);
		if (i<n-1) th = min(ar[i+1], th);
		if (ar[i] >= th) return 0;
	}
	return 1;
}

int work(int k) {
	if (k < 0 || k >= n) return 0;
	int ret = 0;
	for (int j = 0; j < n; ++j) {
		if (k == j) continue;
		// try swap
		swap(ar[k], ar[j]);
		int safe = 1;
		for (int idx2 = 0; idx2 < (int)prob.size(); ++idx2) {
			int i = prob[idx2];
			safe &= check(i);
			safe &= check(i+1);
			safe &= check(i-1);
		}
		safe &= check(j);
		safe &= check(j+1);
		safe &= check(j-1);
		// cleanup
		swap(ar[k], ar[j]);
		pair<int,int> swap_pair = make_pair(min(k,j),max(k,j));
		if (safe && !vis[swap_pair]) {
			/* printf("%d %d\n", swap_pair.first, swap_pair.second); */
			vis[swap_pair] = 1;
			++ret;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ar[i]);

	for (int i = 0; i < n; ++i) {
		if (!check(i)) prob.push_back(i);
	}

	if (prob.size() > 30) {
		puts("0");
	}
	else {
		int ans = 0;
		for (int idx = 0; idx < (int)prob.size(); ++idx) {
			int k = prob[idx];
			ans += work(k) + work(k-1) + work(k+1);
		}
		printf("%d\n", ans);
	}

	return 0;
}
