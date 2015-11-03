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

#define MAXN 20000

const ll INF = 1e15;

int main(){
    int ntc;
	cin.sync_with_stdio(false);

    cin >> ntc;
    for (int itc = 1; itc <= ntc; ++itc) {
    	int n, m, q;
    	cin >> n >> m >> q;
    	vector<int> edge[MAXN+5], rev_edge[MAXN+5];
    	vector<ll> cost[MAXN+5], rev_cost[MAXN+5];
    	int vis[MAXN+5];
    	ll dist_s[MAXN+5], dist_e[MAXN+5];
    	for (int i = 0; i < n; ++i) {
    		dist_s[i] = INF;
    		dist_e[i] = INF;
    	}
    	for (int i = 0; i < m; ++i) {
    		int a, b;
    		ll c;
    		cin >> a >> b >> c;
    		edge[a].PB(b);
    		cost[a].PB(c);

    		rev_edge[b].PB(a);
    		rev_cost[b].PB(c);
    	}

    	priority_queue<pair<ll, int> > PQ;

		RESET(vis,0);
    	PQ.push(MP(0, 0));
    	while (!PQ.empty()) {
    		ll c = -PQ.top().F;
    		int v = PQ.top().S;
    		PQ.pop();

    		if (vis[v]) continue;
    		dist_s[v] = c;
    		vis[v] = 1;

    		for (int i = 0; i < SZ(edge[v]); ++i) {
    			int u = edge[v][i];
    			ll d = cost[v][i];
				PQ.push(MP(-(c + d), u));
    		}
    	}

		RESET(vis, 0);
		PQ.push(MP(0, n-1));
		while (!PQ.empty()) {
			ll c = -PQ.top().F;
			int v = PQ.top().S;
			PQ.pop();

			if (vis[v]) continue;
			dist_e[v] = c;
			vis[v] = 1;

			for (int i = 0; i < SZ(rev_edge[v]); ++i) {
				int u = rev_edge[v][i];
				ll d = rev_cost[v][i];
				PQ.push(MP(-(c + d), u));
			}
		}

		cout << "Case #" << itc << ":\n";
		for (int i = 0; i < q; ++i) {
			int a, b;
			ll c;
			cin >> a >> b >> c;
			if (dist_s[a] + dist_e[b] + c < dist_s[n-1]) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}

	}
	return 0;
}

