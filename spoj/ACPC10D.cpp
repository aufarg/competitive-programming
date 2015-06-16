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

#define INF 1000000000000000LL

int main(){
    int N;
    int tcount = 1;
    while (scanf("%d", &N), N != 0) {
        ll next[3], cur[3] = { INF, 0, INF };
        for (int i = 0; i < N-1; ++i) {
            for (int j = 0; j < 3; ++j) next[j] = INF;
            for (int j = 0; j < 3; ++j) {
                int a;
                scanf("%d", &a);
                for (int k = -1; k <= 1; ++k) {
                    if (j + k >= 0 && j + k < 3) {
                        MN(next[j+k], cur[j] + a);
                    }
                }
                if (j + 1 < 3) MN(cur[j+1], cur[j] + a);
            }
            for (int j = 0; j < 3; ++j) {
                cur[j] = next[j];
            }
        }
        int a, b;
        scanf("%d%d", &a, &b);
        ll ans = min(cur[0] + a + b, cur[1] + b);
        scanf("%d", &a);
        cout << tcount << ". " << ans << endl;
        ++tcount;
    }
    return 0;
}
