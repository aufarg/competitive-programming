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
#define F first
#define S second
#define MP make_pair
#define PB push_back

//macros
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
#define MAXC 1000000000

int main(){
	int n, m;
	int dur[MAXN+5];
	int dep[MAXN+5];
	int ans[MAXN+5];
	vector<int> edge[MAXN+5];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &dur[i]);
		ans[i] = MAXC;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].PB(b);
		++dep[b];
	}
	queue<pair<int, int> > Q;
	int vis[MAXN+5];
	for (int i = 0; i < n; ++i) {
		if (!dep[i]) Q.push(MP(i, 0));
	}
	while (!Q.empty()) {
		int id = Q.front().F;
		int time = Q.front().F;
		Q.pop();
		if (dep[id]) {
			MN(ans[id], time);
		}
		else {
			if (vis[id]) continue;
			vis[id] = 1;
			for (int i = 0; i < SZ(edge[id]); ++i) {
				Q.push( MP(edge[id][i], ans[id] + dur[id]));
			}
		}

	}
	for (int i = 0; i < n; ++i) {
		int mn = MAXC;
		int mx = 0;
		for (int j = 0; j < SZ(edge[i]); ++j) {
			MX(mx, ans[j]);
		}
		for (int j = 0; j < SZ(edge[i]); ++j) {
			MN(mn, mx-ans[j]);
		}
		if (mn > 0) printf("%d %d\n", i, mn);
	}
	return 0;
}



