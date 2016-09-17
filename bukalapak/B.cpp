#include <cstdio>

using namespace std;

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int i = 0; i < ntc; ++i) {
		int a;
		scanf("%d", &a);
		long long k = 1;
		int ans = 0;
		while (k <= a) {
			k *= 2;
			++ans;
		}
		printf("%d\n", ans);
	}
}
