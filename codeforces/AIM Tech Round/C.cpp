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

#define MAXN 500

int n, m;
int adj[MAXN+5][MAXN+5];
int vis[MAXN+5];
char ans[MAXN+5];

int fill(int v, char c) {
	if (ans[v] != 'z' && ans[v] != 'b' && ans[v] != c) return 0;
	if (vis[v]) return 1;
	vis[v] = 1;
	ans[v] = c;
	int ret = 1;
	for (int i = 0; i < v; ++i) {
		if (adj[v][i]) ret &= fill(i, c);
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) ans[i] = 'z';
	for (int i = 0; i < m; ++i) {
		int u,v;
		scanf("%d%d", &u, &v);
		--u, --v;
		adj[u][v] = adj[v][u] = 1;
	}
	
	for (int i = 0; i < n; ++i) {
		vector<int> neigh;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (adj[i][j]) neigh.PB(j);
		}
		if (SZ(neigh)+1 == n) {
			ans[i] = 'b';
			vis[i] = 1;
		}
	}

	bool found = false;
	int v1 = 0, v2 = 0;
	for (int i = 0; i < n && !found; ++i) {
		for (int j = i+1; j < n && !found; ++j) {
			if (ans[i] == 'b' || ans[j] == 'b') continue;
			if (!adj[i][j]) {
				found = true;
				v1  = i, v2 = j;
			}
		}
	}
	
	if (found) {
		vector<int> n1;
		n1.PB(v1);
		for (int i = 0; i < n; ++i) {
			if (adj[v1][i] && ans[i] == 'z') n1.PB(i);
		}
		for (int i = 0; i < SZ(n1); ++i) {
			for (int j = i+1; j < SZ(n1); ++j) {
				if (!adj[n1[i]][n1[j]]) {
					puts("No");
					return 0;
				}
			}
		}

		vector<int> n2;
		n2.PB(v2);
		for (int i = 0; i < n; ++i) {
			if (adj[v2][i] && ans[i] == 'z') n2.PB(i);
		}

		for (int i = 0; i < SZ(n2); ++i) {
			for (int j = i+1; j < SZ(n2); ++j) {
				if (!adj[n2[i]][n2[j]]) {
					puts("No");
					return 0;
				}
			}
		}

		for (int i = 0; i < SZ(n1); ++i) {
			ans[n1[i]] = 'a';
		}
		for (int i = 0; i < SZ(n2); ++i) {
			ans[n2[i]] = 'c';
		}
	}

	for (int i = 0; i < n; ++i) {
		if (ans[i] == 'z') {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	for (int i = 0; i < n; ++i)
		putchar(ans[i]);
	puts("");

	return 0;
}
