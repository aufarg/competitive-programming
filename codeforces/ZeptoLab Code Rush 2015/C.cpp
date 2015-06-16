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
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    return a * (b / GCD(a,b));
}
int main(){
    ll C, Hr, Hb, Wr, Wb;
    cin >> C >> Hr >> Hb >> Wr >> Wb;
    ll redRatio = (Hr) * (Wb);
    ll blueRatio = (Hb) * (Wr);
    if (redRatio < blueRatio) {
        swap(Hr, Hb);
        swap(Wr, Wb);
    }
    ll bigCount = C / Wr;    
    ll smallCount = (C - Wr * bigCount) / Wb;
    ll ans = bigCount * Hr + smallCount * Hb; 
    ll lcm = LCM(Wr, Wb);
    ll times = 0;
    while (bigCount > 0 && times < lcm) {
        ll left = C - bigCount * Wr - smallCount * Wb;
        ll mult = (Wb - left) / Wr + ( ( (Wb - left) % Wr > 0) ? 1 : 0 );
        bigCount-= mult;
        times += mult * Wr;
        smallCount = (C - Wr * bigCount) / Wb;
        MX(ans, bigCount * Hr + smallCount * Hb); 
    }
    cout << ans << endl;

    return 0;
}
