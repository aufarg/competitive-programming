#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a % 2) {
			printf("%d\n", a);
			continue;
		}
		int ans = 0;
		while (a) {
			int lsb = a % 2;
			ans = ans * 2 + lsb;
			a /= 2;
		}
		printf("%d\n", ans);
	}
}
