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

#define MAXN 100000
#define MAXV 100000

int main(){
    int n;
    scanf("%d", &n);
    
    //int w[MAXN+5];
    vector<pii> points[2*MAXN+5];
    int idx[2*MAXV+5];
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	points[y-x + MAXV].PB(MP(x,y));
    }

    for (int i = 0; i <= 2*MAXV; ++i) {
    	idx[i] = 0;
    	if (SZ(points[i])) {
    		sort(ALL(points[i]));
		}
    }

	int x = -MAXV, y = -MAXV;
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
    	int v;
    	scanf("%d", &v);
    	
    	v += MAXV;
    	if (idx[v] >= SZ(points[v])) {
    		puts("NO");
    		return 0;
    	}
    	pii current = points[v][idx[v]++];

		int rv = v + 1, lv = v - 1;
		if (idx[lv] > 0) {
			pii leftNeighbor = points[lv][idx[lv]-1];
			if (current.F <= leftNeighbor.F && current.S <= leftNeighbor.S) {
				puts("NO");
				return 0;
			}
		}
		if (idx[rv] > 0) {
			pii rightNeighbor = points[rv][idx[rv]-1];
			if (current.F <= rightNeighbor.F && current.S <= rightNeighbor.S) {
				puts("NO");
				return 0;
			}
		}
		MX(x, current.F); MX(y, current.S);
		ans.PB(current);
	}

	puts("YES");
	for (int i = 0; i < SZ(ans); ++i) {
		printf("%d %d\n", ans[i].F, ans[i].S);
	}
	return 0;
}

