#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a,b;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x != 0) a.push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x != 0) b.push_back(x);
	}

	assert((int)a.size() == n-1);
	assert((int)b.size() == n-1);
	int p = 0, q = 0;
	while (p < (int)a.size() && a[p] != 1) ++p;
	while (q < (int)b.size() && b[q] != 1) ++q;

	for (int i = 0; i < n-1; ++i) {
		int pm = (p+i) % (n-1);
		int qm = (q+i) % (n-1);
		if (a[pm] != b[qm]) {
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	return 0;
}
