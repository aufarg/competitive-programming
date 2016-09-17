#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 500000

long long a[MAXN+5];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);

	sort(a,a+n);
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%lld", a[i]);
	}
	puts("");
}
