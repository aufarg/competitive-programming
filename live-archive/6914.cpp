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
#define F first
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

#define MAXN 8
#define MAXM 8
#define MAXK 64

#define MOD 1000000007

int main(){
	ll comb[MAXN*MAXM + 5][MAXN*MAXM + 5];
	RESET(comb, 0);
	comb[0][0] = 1;
	for (int i = 1; i <= MAXN * MAXM; ++i)
		for (int j = 0; j <= i; ++j) {
			comb[i][j] = (j && j < i) ? comb[i-1][j-1] + comb[i-1][j] : 1;
			comb[i][j] %= MOD;
		}

	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int N, M, K;
		scanf("%d%d%d", &N, &M, &K);

		ll dp[MAXN+5][MAXK+5][(1<<M)+5];
		RESET(dp, 0);

		for (int m = 0; m < (1 << M); ++m) {
			int nm = m;
			int bcount = 0;
			if (nm & (1 << (M-1))) continue;
			bool last = false;
			for (int bc = M-1; bc >= 0; --bc) {
				int mask = 1 << bc;
				bool block = (nm & mask) ? true : false;
				if (block) ++bcount;
				if (block || last) {
					block = true;
					nm |= mask;
				}
				last = block;
			}
			dp[0][K-bcount][nm] += 1;
		}

		for (int i = 0; i < N-1; ++i) {
			for (int nxt = 0; nxt < (1 << M); ++nxt) {
				for (int m = 0; m < (1 << M); ++m) {
					int bcount = 0;
					bool lastBlock = true;

					int m_next = nxt;
					for (int bc = M-1; bc >= 0; --bc) {
						int mask = 1 << bc;
						bool curBlock = (m & mask) ? true : false;
						bool nxtBlock = (nxt & mask) ? true : false;

						if (nxtBlock) ++bcount;
						else if (curBlock && lastBlock) {
							nxtBlock = true;
							m_next |= mask;
						}

						lastBlock = nxtBlock;
					}

					for (int k = 0; k + bcount <= K; ++k) {
						dp[i+1][k][m_next] += dp[i][k + bcount][m];
						dp[i+1][k][m_next] %= MOD;
					}
				}
			}
		}

		ll ans = 0;
		for (int i = 0; i < (1<<M); ++i) {
			if (i & 1) continue;
			for (int k = 0; k <= K; ++k)
				ans = (ans + dp[N-1][k][i]) % MOD;
		}
		ll total = 0;
		for (int i = 0; i <= K; ++i) {
			total = (total + comb[N*M][i]) % MOD;
		}
		printf("Case #%d: %lld\n", itc, (total - ans + MOD) % MOD);
	}
	return 0;
}
