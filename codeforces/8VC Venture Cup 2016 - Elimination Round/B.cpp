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

#define MAXN 200

int mem[MAXN+5][MAXN+5][MAXN+5];
int vis[MAXN+5][MAXN+5][MAXN+5];
int red, green, blue;

int dp(int r, int g, int b) {
	if (r < 0 || g < 0 || b < 0) return 0;
	if (r == 1 && g == 0 && b == 0) return 1;
	if (r == 0 && g == 1 && b == 0) return 2;
	if (r == 0 && g == 0 && b == 1) return 4;
	int &ret = mem[r][g][b];
	if (vis[r][g][b]) return ret;
	vis[r][g][b] = 1;
	if (g && b) ret |= dp(r+1, g-1, b-1);
	if (r && b) ret |= dp(r-1, g+1, b-1);
	if (r && g) ret |= dp(r-1, g-1, b+1);
	if (r > 1) ret |= dp(r-1, g, b);
	if (g > 1) ret |= dp(r, g-1, b);
	if (b > 1) ret |= dp(r, g, b-1);
	return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    string s, ans;
    cin >> s;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'R') ++red;
    	if (s[i] == 'G') ++green;
    	if (s[i] == 'B') ++blue;
    }
	int mask = dp(red, green, blue);
	if (mask & 4) ans += 'B';
	if (mask & 2) ans += 'G';
	if (mask & 1) ans += 'R';

	cout << ans << endl;
    return 0;
}

