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
typedef pair<ll,ll> pll;
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
int n;
pair<pii,int> p[MAXN+5];


ll sqr(ll a) { return a*a; }

ll dist(pii a, pii b) {
	return sqr(a.F-b.F) + sqr(a.S-b.S);
}

pair<int, int> closest() {
	ll min_dist = dist(p[0].F, p[1].F);
	int idx = 1;
	for (int i = 2; i < n; ++i) {
		ll d = dist(p[0].F, p[i].F);
		if (d < min_dist) {
			min_dist = d;
			idx = i;
		}
	}

	return MP(0, idx);
}

ll cross(pii a, pii b, pii c) {
	pll dab = MP(b.F-a.F,b.S-a.S);
	pll dac = MP(c.F-a.F,c.S-a.S);
	return dab.F * dac.S - dab.S * dac.F;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		pii pt;
		scanf("%d%d", &pt.F, &pt.S);
		p[i] = MP(pt, i+1);
	}

	sort(p, p+n);
	pair<int,int> p_close = closest();
	int f_idx = p_close.F;
	int s_idx = p_close.S;

	int f_close = -1;
	ll f_dist = -1;
	for (int i = 0; i < n; ++i) {
		if (i != f_idx && i != s_idx) {
			ll s = cross(p[i].F, p[f_idx].F, p[s_idx].F);
			if (s != 0) {
				ll d = dist(p[f_idx].F, p[i].F);
				if (f_dist == -1 || f_dist > d) {
					f_dist = d;
					f_close = i;
				}
			}
		}
	}

	printf("%d %d %d\n", p[f_idx].S, p[s_idx].S, p[f_close].S);


	return 0;
}

