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

#define MAXN 100000
#define MOD 1000000007
int ntc;
int n, x; 
ll m;
ll a[MAXN+5];

ll powmod(ll a, ll b) {
	if (!b) return 1;
	ll ret = powmod(a, b/2);
	ret = (ret*ret)%MOD;
	return (b%2) ? (ret*a)%MOD : ret;
}

ll inv(ll k) {
	return powmod(k, MOD-2);
}

int main(){
	scanf("%d", &ntc);
	while (ntc--) {
		scanf("%d%d%lld", &n, &x, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			a[i] %= MOD;
		}
		ll mult = 1;
		ll ans = 0;
		for (int i = x; i >= 0; --i) {
			ans = (ans + mult*a[i]) % MOD;
			ll k = (x-i+1);
			mult = (mult * ((m-1+k) % MOD) % MOD) * inv(k) % MOD;
		}
		printf("%lld\n", ans);
	}
	
    return 0;
}

