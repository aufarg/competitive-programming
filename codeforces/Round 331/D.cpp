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

#define MAXN 2000
#define MAXV 200000000

int n, h;
double p;

int x[MAXN+5];
bool vis[MAXN+5][MAXN+5][2][2];
double memo[MAXN+5][MAXN+5][2][2];

double dp(int l, int r, int ldir, int rdir) {
	if (l > r) return 0;
	if (vis[l][r][ldir][rdir]) return memo[l][r][ldir][rdir];

	double ret = 0;

	int ldist = x[l] - x[l-1];
	int lcover = min(h, ldist - ((ldir) ? h : 0));
	int rdist = x[r+1] - x[r];
	int rcover = min(h, rdist - ((rdir) ? h : 0));

	if (lcover < 0) {
		ret = dp(l+1, r, 1, rdir) + ((l == r) ? max(0, rcover) : min(h, x[l+1] - x[l]));
	}
	else if (rcover < 0) {
		ret = dp(l, r-1, ldir, 1) + ((l == r) ? max(0, lcover) : min(h, x[r] - x[r-1]));
	}
	else {
		// Left - Fall to right
		ret = ret + (dp(l+1, r, 1, rdir) + ((l == r) ? rcover : min(h, x[l+1] - x[l])) ) * (1-p) * 0.5;
		// Left - Fall to left
		ret = ret + (dp(l+1, r, 0, rdir) + lcover) * p * 0.5;

		// Right - Fall to left
		ret = ret + (dp(l, r-1, ldir, 1) + ((l == r) ? lcover : min(h, x[r] - x[r-1])) )  * p  * 0.5; 
		// Right - Fall to right
		ret = ret + (dp(l, r-1, ldir, 0) + rcover) * (1-p) * 0.5;
	}

	// Save result
	vis[l][r][ldir][rdir] = true; memo[l][r][ldir][rdir] = ret;
	return ret;
}

int main(){
	scanf("%d%d%lf", &n, &h, &p);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	x[0] = -MAXV; x[n+1] = MAXV;

	printf("%lf\n", dp(1, n, 0, 0));
	return 0;
}

