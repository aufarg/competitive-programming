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

#define MAXD 2000
#define MOD 1000000007

ll mem[MAXD+5][MAXD+5];
int vis[MAXD+5][MAXD+5];
ll nck[MAXD+5][MAXD+5];

ll dp(int num, int cur) {
	if (num == 0) {
		if (cur == 0) return 1;
		else return 0;
	}
	ll &ret = mem[num][cur];
	if (vis[num][cur]) return ret;
	vis[num][cur] = 1;
	ret = dp(num-1, cur+1);
	if (cur > 0) ret = (ret + dp(num-1, cur-1)) % MOD;
	return ret;
}

int main(){
	nck[0][0] = 1;
	for (int i = 1; i <= MAXD; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == i || j == 0) nck[i][j] = 1;
			else nck[i][j] = (nck[i-1][j-1] + nck[i-1][j]) % MOD;
		}
	}
    int n, m;
    string bought;
    scanf("%d%d", &n, &m);
    cin >> bought;
    int v = 0;
    for (int i = 0; i < m; ++i)
    	if (bought[i] == '(') ++v;
		else --v;

    int d = n-m;

    ll ans = 0;
	for (int t = max(0, -v); t <= d; ++t) {
		for (int i = 0; i <= d; ++i) {
			if (i < t) continue;
			if ( (i-t) % 2 == 1) continue;
			int pbb = (i-t) / 2;
			ll cat = nck[2*pbb][pbb] / (pbb+1);
			ll cnt = (nck[pbb][t] * cat) % MOD;
			assert(t+v >= 0);
			printf("%d %d %d %d %d %d %d\n", t, i, d-i, t+v, cnt, cat, dp(d-i, t+v));
			ans = (ans + (cnt * dp(d-i, t+v)) % MOD) % MOD;
		}
	}
	cout << ans << endl;

	return 0;
}

