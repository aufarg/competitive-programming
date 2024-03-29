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

#define INF 1000000

int main(){
    int ntc;
    scanf("%d", &ntc);
    for (int i = 0; i < ntc; ++i) {
    	int a, b, c;
    	scanf("%d%d%d", &a, &b, &c);
    	queue<pair<pair<int, int>, int > > Q;
		map<pair<int,int>, int> vis;
    	Q.push(MP(MP(0, 0), 0));
    	int ans = -1;
    	while (!Q.empty()) {
    		pair<int, int> p = Q.front().F;
    		int step = Q.front().S;
    		Q.pop();
			if (p.F == c || p.S == c) {
				ans = step;
				break;
			}
			if (EXIST(p, vis)) 
				continue;

			vis[p] = 1;

			pair<int, int> tmp = p;
			tmp.F = a;
			Q.push(MP(tmp, step+1));
			tmp = p; tmp.S = b;
			Q.push(MP(tmp, step+1));
			tmp = p; tmp.F = 0;
			Q.push(MP(tmp, step+1));
			tmp = p; tmp.S = 0;
			Q.push(MP(tmp, step+1));

			tmp = p; tmp.S += tmp.F; tmp.F = 0; 
			if (tmp.S > b) {
				tmp.F = tmp.S - b;
				tmp.S = b;
			}
			Q.push(MP(tmp, step+1));

			tmp = p; tmp.F += tmp.S; tmp.S = 0; 
			if (tmp.F > a) {
				tmp.S = tmp.F - a;
				tmp.F = a;
			}
			Q.push(MP(tmp, step+1));
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}

