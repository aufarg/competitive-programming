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
typedef pair<ll, ll> pll;

#define MAXN 100000
int n;
ll sum[MAXN+5];
vector<ll> arv;
vector<pll> ar;

ll cost(ll minlvl, int idx) {
	int lvlidx = upper_bound(ALL(arv), minlvl)-arv.begin()-1;
	idx = min(idx, lvlidx);
	if (idx < 0) return 0;
	else return minlvl * (idx+1) - sum[idx];
}

int main(){
	ll A, cf, cm, m;

	scanf("%d", &n);
	cin >> A >> cf >> cm >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		ar.PB(MP(x,i));
	}
	sort(ALL(ar));
	for (int i = 0; i < n; ++i) {
		sum[i] = (i) ? sum[i-1] + ar[i].F : ar[i].F;
		arv.PB(ar[i].F);
	}

	ll ans = 0;
	ll anslvl = 0;
	ll fullidx = n;
	ll maxcost = 0;
	for (int i = n-1; i >= 0 && m-maxcost >= 0; --i) {
		ll l = 0, r = A;
		for (int bs = 0; bs < 40; ++bs) {
			ll mid = (l+r)/2;

			ll tmp = cost(mid, i);
			if (tmp <= m - maxcost) l = mid;
			else r = mid;
		}

		ll mlevel = (l+r)/2;
		ll tans = cm * mlevel + (n-i-1) * cf;
		//printf("%d %d %d\n", maxcost, mlevel, tans);
		if (tans > ans) {
			anslvl = mlevel;
			ans = tans;
			fullidx = i;
		}
		maxcost += A-ar[i].F;
	}

	if (maxcost <= m && cf * n + A * cm > ans) {
		ans = cf * n + A * cm;
		anslvl = -1;
		fullidx = -1;
	}

	cout << ans << endl;
	ll ans_arr[MAXN+5];
	for (int i = 0; i < n; ++i) {
		if (ar[i].F < anslvl) ar[i].F = anslvl;
		if (i > fullidx) ar[i].F = A;
		ans_arr[ar[i].S] = ar[i].F;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans_arr[i] << ' ';
	}
	puts("");
}
