#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1000

int vis[MAXN+5][MAXN+5][5], memo[MAXN+5][MAXN+5][5];

int dp(int H, int A, int choice) {
	if (vis[H][A][choice]) return memo[H][A][choice];
	vis[H][A][choice] = 1;
	int &ret = memo[H][A][choice];
	switch (choice) {
		case 0: 
			H += 3;
			A += 2;
			break;
		case 1:
			H -= 5;
			A -= 10;
			break;
		case 2:
			H -= 20;
			A += 5;
			break;
		default:
			assert(false);
	}

	if (H <= 0 || A <= 0) return 0;
	for (int c = 0; c < 3; ++c) {
		if (c != choice) ret = max(ret, dp(H,A,c));
	}
	ret += 1;
	
	return ret;
}

int main() {
	int NTC;
	scanf("%d", &NTC);
	for (int itc = 0; itc < NTC; ++itc) {
		int H,A;
		scanf("%d%d", &H, &A);
		printf("%d\n", max(dp(H,A,0), max(dp(H,A,1), dp(H,A,2))));
	}
	return 0;
}
