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

#define MAXN 500000

ll a[MAXN+5];
ll token[MAXN+5];
map<pair<int, int>, ll> vis, memo;
vector<int> edge[MAXN+5];

ll dp(int v, int cutnode) {
	if (EXIST(MP(v, cutnode), vis)) return memo[MP(v, cutnode)];
	ll ret = a[v];
	if (token[v] < 0) {
		token[v] = 0;
		for (int i = 0; i < SZ(edge[v]); ++i) {
				token[v] += dp(edge[v][i], v);
		}
	}
	vis[MP(v, cutnode)] = 1; memo[MP(v, cutnode)] = ret;
	return ret;
}

int main(){
	int n;
	ll sum = 0;
	RESET(token, -1);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]); 
		sum += a[i];
	}
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].PB(v);
		edge[v].PB(u);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll enemy = 0;
		for (int j = 0; j < SZ(edge[i]); ++j) {
			MX(enemy, sum-(dp(i, edge[i][j])));
		}
		MX(ans, sum-enemy);
	}
	printf("%lld\n", ans);
	return 0;
}


