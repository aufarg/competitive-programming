#include <cstdio>

using namespace std;

int main() {
	int N;
	do {
		scanf("%d", &N);
		if (N == 0) break;

		int next = 4;
		int ans = 1;
		for (int i = 1; i <= N; ++i) {
			ans += next;
			next += 3;
		}
		printf("%d\n", ans);
	} while (N != 0);

	return 0;
}
