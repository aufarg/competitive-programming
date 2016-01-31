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

#define MAXN 50000
#define MOD 1000000007

int n, k, x;
int a[MAXN+5];
ll cnt[110];

ll mul(ll a, ll b) {
	return (a*b) % MOD;
}

ll mulmod(ll a, ll b, ll c) {
	return (a*b) % c;
}

ll powmod(ll a, ll base, ll mod) {
	if (!base) return 1;
	ll ret = powmod(a, base / 2, mod);
	if (base % 2) {
		return mulmod(mulmod(ret, ret, mod), a, mod);
	}
	else {
		return mulmod(ret, ret, mod);
	}
}

#define THRESHOLD 50000
int vis[THRESHOLD+5];
vector<ll> memo[THRESHOLD+5];

map<ll, vector<ll> > smemo;

vector<ll> dnc(ll b) {
	if (b < THRESHOLD) {
		if (vis[b]) return memo[b];
	}
	else {
		if (EXIST(b, smemo)) return smemo[b];
	}
	printf("%d\n", b);
	vector<ll> ret;
	for (int i = 0; i < x; ++i) {
		ret.PB(0);
	}
	if (b == 1) {
		for (int i = 1; i <= 9; ++i) {
			ret[i%x] += cnt[i];
			ret[i%x] %= MOD;
		}
	}
	else {
		ll m = b/2;
		vector<ll> r1 = dnc(m);
		vector<ll> r2 = dnc(b-m);
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < x; ++j) {
				ll mod = (i*powmod(10, b-m, x)+j)%x; 
				ret[mod] = (ret[mod] + mul(r1[i],r2[j])) % MOD;
			}
		}
	}
	if (b < THRESHOLD) {
		vis[b] = 1;
		memo[b] = ret;
	}
	else {
		smemo[b] = ret;
	}
	return ret;
}

int main(){
	int b;
	scanf("%d%d%d%d", &n, &b, &k, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}

	vector<ll> ans = dnc(b);
	cout << ans[k] % MOD << endl;

	return 0;
}

