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

#define MAXN 50

int n, m;
int adj[MAXN+5][MAXN+5];

void cgraph(ll mask) {
	int u = 1, v = 2;
	int cur = 0;
	RESET(adj, 0);
	while (cur < m) {
		if (mask & (1LL << cur)) {
			adj[u][v] = adj[v][u] = 1;
		}
		++v;
		if (v > n) {
			++u;
			v = u+1;
		}
		++cur;
	}
	assert(u == n && v == n+1);
}

int check() {
	int dist[MAXN+5][MAXN+5];
	RESET(dist, 0);
	vector<pii> g;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j) {
			if (adj[i][j]) g.PB(MP(i,j));
			dist[i][j] = dist[j][i] = (adj[i][j]) ? 1 : 1000;
		}

	int maxdistfromone = 0;
	int truedist = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
	}

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) {
			truedist = max(truedist, dist[i][j]);
			if (i == 1) 
				maxdistfromone = max(maxdistfromone, dist[i][j]);
		}


	vector<int> vc;
	int algmax = 0;
	for (int i = 1; i <= n; ++i) {
		if (dist[1][i] == maxdistfromone) vc.PB(i);
	}
	for (int i = 0; i < SZ(vc); ++i) {
		for (int j = 1; j <= n; ++j) {
			int u = vc[i];
			algmax = max(algmax, dist[u][j]);
		}
	}

	if (algmax == truedist) {
		return 0;
	}
	else {
		printf("%d\n", SZ(g));
		for (int i = 0; i < SZ(g); ++i) {
			printf("%d %d\n", g[i].F, g[i].S);
		}
		return 1;

	}

}

int main(){
	scanf("%d", &n);
	m = n*(n-1)/2;
	RESET(adj, 0);
	for (ll i = 0; i < (1<<m); ++i) {
		cgraph(i);
		if (check()) break;
	}
	return 0;
}


