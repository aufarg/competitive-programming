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

#define MAXN 1000
int n;
int a[MAXN+5];
int vis[MAXN+5][MAXN+5][2], memo[MAXN+5][MAXN+5][2];

int dp(int l, int r, int turn) {
	if (l > r) return 0;
	int &ret = memo[l][r][turn];
	if (vis[l][r][turn]) return ret;
	vis[l][r][turn] = 1;

	if (turn == 0) {
		ret = max(dp(l+1, r, !turn)+a[l], dp(l, r-1, !turn)+a[r]);
	}
	else {
		if (a[l] < a[r]) ret = dp(l, r-1, !turn)-a[r];
		else ret = dp(l+1, r, !turn)-a[l];
	}
	return ret;
}

int main(){
    int tc = 0;
    while (scanf("%d", &n), n != 0) {
    	RESET(vis, 0);
    	for (int i = 0; i < n; ++i) {
    		scanf("%d", &a[i]);
    	}
    	++tc;
    	printf("In game %d, the greedy strategy might lose by as many as %d points.\n", 
    			tc, dp(0, n-1, 0));
    }
    return 0;
}

