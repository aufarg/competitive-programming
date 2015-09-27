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
#define MOD 1000000007
#define MAXN 10005

string A, B;

ll memo[MAXN][10][2];
int vis[MAXN][10][2];

ll dp(int pos, int last, int type) {
	if (!pos) { return 1; }
	if (vis[pos][last][type]) return memo[pos][last][type];
	int ret = 0;
	if ( (type) ^ (pos % 2 == 0) )  {
		for (int i = last+1; i <= 9; ++i) {
			ret += dp(pos-1, i, type);
		}
	}
	else {
		for (int i = last-1; i >= 0; ++i) {
			ret += dp(pos-1, i, type);
		}
	}
	vis[pos][last][type] = 1; memo[pos][last][type] = ret;
	return ret;
}

ll dp(int pos, int last, int type) {
	
}

int main(){
	cin.sync_with_stdio(false);

	int ntc;
	cin >> ntc;
	while (ntc--) {
		cin >> A >> B;
		if (SZ(A) > SZ(B)) swap(A,B);
		if (SZ(A) == SZ(B) && A > B) swap(A,B);

		ll ans = 0;
		for (int len = SZ(A)+1; len < SZ(B); ++len) {
			for (int i = 1; i <= 9; ++i) {
				ans += dp(len-1, i, 0);
				ans += dp(len-1, i, 1);
				ans = ans % MOD;
			}
		}
		for(int i = 1; i <= 9; ++i) {
			
		}

		cout << ans << endl;

	}
	return 0;
}

