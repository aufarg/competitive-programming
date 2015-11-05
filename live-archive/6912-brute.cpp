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

#define MAXPROB 170
#define MAXDRINK 24

#define INF 1000000000

int nprob, en_ini, en_gain, ndrink, dr_gain, dr_crash;
int en_need[MAXPROB+5], point[MAXPROB+5];
int ans;

int vis[MAXPROB+5][MAXPROB*10+5][MAXDRINK+5][1 << 2];
int memo[MAXPROB+5][MAXPROB*10+5][MAXDRINK+5][1 << 2];

int dp(int prob, int score, int dcount, int dmask) {
	if (prob == nprob) {
		if (score == 0)
			return 0;
		else
			return INF;
	}
	if (vis[prob][score][dcount][dmask])
		return memo[prob][score][dcount][dmask];

	int cur_dmask = dmask;
	int crash = cur_dmask & 2;
	cur_dmask <<= 1;
	
	// Needed energy to attempt without coffee
	int attempt_energy = dp(prob+1, score-point[prob], dcount, cur_dmask) + en_need[prob];
	// Needed energy if we sleep now
	int sleep_energy = dp(prob+1, score, dcount, cur_dmask) - en_gain;

	// Needed energy to attemp with coffe
	int coffee_attempt_energy = INF;
	if (attempt_energy - dr_gain) {
		coffee_attempt_energy = dp(prob+1, score-point[prob], dcount-1, cur_dmask | 1) + en_need[prob] - dr_gain;
	}

	int ret = min(attempt_energy, min(sleep_energy, coffee_attempt_energy));
	if (crash) ret += dr_crash;
	if (ret > en_ini) ret = INF;
	vis[prob][score][dcount][dmask] = 1;
	memo[prob][score][dcount][dmask] = ret;
	return ret;
}

#define MAXK 1000
#define MAXN 1000

int main(){
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int n, k;
		int pr[MAXK+5];
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; ++i) {
			scanf("%d", &pr[i]);
		}
		int ans = 0;
		for (int i = 0; i < (1 << k); ++i) {
			int tmp = 0;
			bool on[MAXN+5];
			RESET(on, 0);
			for (int c = 0; c < k; ++c) {
				if (i & (1<<c)) {
					for (int nn = pr[c]; nn <= n; nn += pr[c]) {
						on[nn] = !on[nn];
						if (on[nn]) ++tmp;
						else --tmp;
					}
				}
			}
			MX(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}

