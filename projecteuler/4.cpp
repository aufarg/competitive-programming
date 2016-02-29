#include <bits/stdc++.h>

using namespace std;

bool palind(int c) {
	int r = 0;
	int t = 1;
	while (c / t > 0) {
		r = r * 10 + ((c/t)%10);
		t *= 10;
	}
	return (r == c);
}

int main() {
	int ans = 0;
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j) {
			int c = i*j;
			if (palind(c)) {
				ans = max(ans, c);
			}
		}
	printf("%d\n", ans);
	return 0;
}
