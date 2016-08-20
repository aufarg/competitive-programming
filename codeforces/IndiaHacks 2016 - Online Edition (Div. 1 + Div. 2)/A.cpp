#include <bits/stdc++.h>

using namespace std;

int ar[1005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ar[i]);

	int ok = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			for (int k = j+1; k < n; ++k) {
				if (ar[i] == ar[j] || ar[i] == ar[k] || ar[k] == ar[j]) continue;
				int mx = max(ar[i], max(ar[j],ar[k]));
				int mn = min(ar[i], min(ar[j],ar[k]));
				if (mx-mn <= 2) ok = 1;
			}

	puts(ok ? "YES" : "NO");
	return 0;
}
