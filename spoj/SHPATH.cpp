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

#define MAXN 10000

int main(){
    int ntc;
    scanf("%d", &ntc);
    while(ntc--) {
        int n, q;
        map<string,int> idx;
        vector<int> edge[MAXN+5], cost[MAXN+5];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int p;
            string name;
            cin >> name;
            idx[name] = i;
            scanf("%d", &p);
            for (int j = 0; j < p; ++j) {
                int a, b;
                scanf("%d%d", &a, &b);
                --a;
                edge[i].PB(a);
                cost[i].PB(b);
            }
        }
        scanf("%d", &q);
        int vis[MAXN+5];
        while (q--) {
            RESET(vis, 0);
            string a, b;
            cin >> a >> b;
            int start = idx[a], end = idx[b];
            priority_queue<pair<int, int> > pq;
            pq.push(MP(0, start));
            while (!pq.empty()) {
                int v = pq.top().S;
                int d = -pq.top().F;
                pq.pop();
                if (vis[v]) continue;
                if (v == end) {
                    printf("%d\n", d);
                    break;
                }
                vis[v] = 1;
                for (int i = 0; i < SZ(edge[v]); ++i) {
                    int next = edge[v][i];
                    int need = cost[v][i];
                    if (!vis[next]) pq.push(MP(-d-need, next));
                }
            }
        }
    }
    return 0;
}

