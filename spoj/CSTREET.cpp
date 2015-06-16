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

#define MAXN 1000

int main(){
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n,m;
        ll p;
        vector<int> edge[MAXN+5];
        vector<ll> cost[MAXN+5];
        int vis[MAXN+5];
        RESET(vis,0);

        scanf("%lld", &p);
        scanf("%d%d", &n,&m);
        for (int i = 0; i < m; ++i) {
            int a,b; ll c;
            scanf("%d%d%lld", &a, &b, &c);
            --a; --b;
            edge[a].PB(b); edge[b].PB(a);
            cost[a].PB(c); cost[b].PB(c);
        }
        priority_queue<pair<ll,int> > pq;
        pq.push(MP(0, 0));
        ll ans = 0;
        while (!pq.empty()) {
            pair<ll,int> cur = pq.top();
            pq.pop();
            int v = cur.S;
            if (vis[v]) continue;

            ans -= cur.F;
            vis[v] = 1;
            for (int i = 0; i < SZ(edge[v]); ++i) {
                if (!vis[edge[v][i]])
                    pq.push(MP(-cost[v][i], edge[v][i]));
            }
        }
        printf("%lld\n", ans * p);
    }
    return 0;
}

