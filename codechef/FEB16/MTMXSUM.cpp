/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
#define debug(...) 
#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define first
#define S second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 100000
#define MOD 1000000007LL

ll a[MAXN+5], b[MAXN+5];
int lastA[MAXN+5], lastB[MAXN+5], nxtA[MAXN+5], nxtB[MAXN+5];
ll dA[MAXN+5], ddA[MAXN+5];
ll dB[MAXN+5], ddB[MAXN+5];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[i] = x+i+1;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		b[i] = x+i+1;
	}

	for (int i = 0; i < n; ++i) {
		if (i) {
			int idxA = i-1;
			int idxB = i-1;
			while (idxA >= 0 && a[idxA] <= a[i]) {
				idxA = lastA[idxA];
			}
			while (idxB >= 0 && b[idxB] <= b[i]) {
				idxB = lastB[idxB];
			}
			lastA[i] = idxA;
			lastB[i] = idxB;
		}
		else {
			lastA[i] = -1;
			lastB[i] = -1;
		}
	}

	for (int i = n-1; i >= 0; --i) {
		if (i != n-1) {
			int idxA = i+1;
			int idxB = i+1;
			while (idxA < n && a[idxA] < a[i]) {
				idxA = nxtA[idxA];
			}
			while (idxB < n && b[idxB] < b[i]) {
				idxB = nxtB[idxB];
			}
			nxtA[i] = idxA;
			nxtB[i] = idxB;
		}
		else {
			nxtA[i] = n;
			nxtB[i] = n;
		}
	}

	for (int i = 0; i < n; ++i) {
		int leftA = i-lastA[i]-1, rightA = nxtA[i]-i-1;
		int leftB = i-lastB[i]-1, rightB = nxtB[i]-i-1;
		int lowA = min(leftA, rightA), highA = max(leftA, rightA);
		int lowB = min(leftB, rightB), highB = max(leftB, rightB);
		// Uphill
		ddA[1] = (ddA[1] + a[i]) % MOD;
		ddB[1] = (ddB[1] + b[i]) % MOD;
		ddA[lowA+2] = (ddA[lowA+2] - a[i] + MOD) % MOD;
		ddB[lowB+2] = (ddB[lowB+2] - b[i] + MOD) % MOD;

		// Downhill
		ddA[highA+2] = (ddA[highA+2] - a[i] + MOD) % MOD;
		ddB[highB+2] = (ddB[highB+2] - b[i] + MOD) % MOD;
		ddA[lowA+highA+3] = (ddA[lowA+highA+3] + a[i]) % MOD;
		ddB[lowB+highB+3] = (ddB[lowB+highB+3] + b[i]) % MOD;

		/* puts("A"); */
		/* printf("%d %d\n", leftA, rightA); */
		/* puts("B"); */
		/* printf("%d %d\n", leftB, rightB); */
	}

	ll diffA = 0, diffB = 0;
	ll sumA = 0, sumB = 0;
	for (int i = 1; i <= n; ++i) {
		diffA = (diffA + ddA[i]) % MOD;
		diffB = (diffB + ddB[i]) % MOD;

		sumA = (sumA + diffA) % MOD;
		sumB = (sumB + diffB) % MOD;

		if (i > 1) printf(" ");
		printf("%lld", (sumA * sumB) % MOD);
		/* puts(""); */
		/* printf("%lld %lld\n", sumA, sumB); */
		/* printf("%lld %lld\n", diffA, diffB); */
		/* printf("%lld %lld\n", ddA[i], ddB[i]); */
	}
	puts("");

    return 0;
}

