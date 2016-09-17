#include <bits/stdc++.h>

using namespace std;

int main() {
	int sqsum = 0;
	int sumsq = 0;
	for (int i = 1; i <= 100; ++i) {
		sqsum += i*i;
		sumsq += i;
	}
	printf("%d\n", abs(sumsq*sumsq-sqsum));
	return 0;
}
