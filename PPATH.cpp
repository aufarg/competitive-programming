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

int nprime[10005];
int vis[10005];

int main(){
    int NTC;
    for (int i = 2; i * i <= 10000; ++i) {
        if (!nprime[i]) {
            int t = i * i;
            while (t <= 10000) {
                nprime[t] = 1;
                t += i;
            }
        }
    }
    scanf("%d", &NTC);
    for (int i = 0; i < NTC; ++i) {
        RESET(vis,0);
        int s, e;
        scanf("%d%d", &s, &e);
        queue<pair<int, int> > Q;
        Q.push(MP(s,0));
        int ans = -1;
        while (!Q.empty()) {
            int now = Q.front().F;
            int step = Q.front().S;
            Q.pop();
            if (now == e) {
                ans = step;
                break;
            }
            vis[now] = 1;
            int ten = 1;
            for (int i = 0; i < 4; ++i) {
                int dig = (now / ten) % 10;
                for (int j = -dig + i/3; j < 10-dig; ++j) {
                    if (!nprime[now + j * ten] && !vis[now + j*ten]) {
                        Q.push(MP(now + j * ten, step + 1));
                    }
                }
                ten *= 10;
            }
        }
        if (ans >= 0) printf("%d\n", ans);
        else puts("Impossible");
    }
    return 0;
}
