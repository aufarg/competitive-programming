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

int n, k;
int vis[15][105][(2<<13)+5];
int memo[15][105][(2<<13)+5];

int dp(int nn, int rem, int mask) {
    if (nn == 0) return (!rem);
    if (vis[nn][rem][mask]) return memo[nn][rem][mask];
    int bits = 0;
    int ret = 0;
    for (int i = n-1; i >= 0; --i) {
        if (mask & (1 << i))
            ++bits;
        else 
            ret += dp(nn-1, rem-bits, mask | (1 << i));
    }
    vis[nn][rem][mask] = 1; memo[nn][rem][mask] = ret;
    return ret;
}

int main(){
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        RESET(memo, 0);
        scanf("%d%d", &n, &k);
        printf("%d\n", dp(n, k, 0));
    }

    return 0;
}
