#include <cstdio>

using namespace std;

#define MAXV 1000000

bool prime[MAXV+5];
bool cubefr[MAXV+5];
int ans[MAXV+5];

int main() {
	for (int i = 2; i <= MAXV; ++i) prime[i] = true;
	for (int i = 1; i <= MAXV; ++i) cubefr[i] = true;
	for (int i = 2; i*i <= MAXV; ++i) {
		int j = i*i;
		while (j <= MAXV) {
			prime[j] = false;
			j += i;
		}
	}
	for (int i = 2; i*i*i <= MAXV; ++i) {
		int c = i*i*i;
		int j = c;
		while (j <= MAXV) {
			cubefr[j] = false;
			j += c;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= MAXV; ++i) {
		if (cubefr[i]) {
			ans[i] = ++cnt;
		}
	}
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int n;
		scanf("%d", &n);
		printf("Case %d: ", itc);
		if (cubefr[n]) {
			printf("%d\n", ans[n]);
		}
		else {
			puts("Not Cube Free");
		}
	}
	return 0;
}
