#include <bits/stdc++.h>

using namespace std;

#define MAXN 10
long long a[MAXN+5];
int diff[MAXN+5][MAXN+5];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);

	if (n == 5) {
		puts("0 1 2 3 4");
		return 0;
	}
	else {
		for (int i = 0; i < n; ++i) {
			int idx = i;
			int d = 0;
			do {
				d += a[idx]-a[(idx+1)%n];
				idx = (idx+5)%n;
				diff[i][idx] = d;
			} while (idx != i);
		}
		for (int i = 0; i < n; ++i) {
			int d = 0;
			for (int j = i; j < i+4; ++j) {
				d += diff[j%n][(j+1)%n];
				a[i] += d;
			}
		}

		long long ans = 0;
		int found = 0;
		vector<int> print;
		for (int i1 = 0; i1 < n; ++i1)
			for (int i2 = i1+1; i2 < n; ++i2)
				for (int i3 = i2+1; i3 < n; ++i3)
					for (int i4 = i3+1; i4 < n; ++i4)
						for (int i5 = i4+1; i5 < n; ++i5) {
							long long v = a[i1] + a[i2] + a[i3] + a[i4] + a[i5];
							if (!found || ans > v) {
								ans = v;
								print.clear();
								print.push_back(i1);
								print.push_back(i2);
								print.push_back(i3);
								print.push_back(i4);
								print.push_back(i5);
							}
							found = 1;
						}

		for (int i = 0; i < (int)print.size(); ++i) {
			if (i) printf(" ");
			printf("%d", print[i]);
		}
		puts("");

	}
}
