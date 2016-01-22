#include <cstdio>

using namespace std;

#define MOD 10000007

long long powmod(int n, int k) {
	if (k == 0) return 1;
	long long ret = powmod(n, k/2);
	if (k%2) return (n * (ret * ret % MOD)) % MOD;
	else return (ret * ret) % MOD;
}

long long z(int N, int K) {
	return powmod(N, K) + powmod(N, N) % MOD;
}

int main() {
	int N, K;
	while (scanf("%d%d", &N, &K), N != 0 || K != 0) {
		printf("%lld\n", (z(N,K) + 2 * z(N-1,K)) % MOD);
	}
	return 0;
}
