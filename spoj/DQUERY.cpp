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

#define C_SZ 75
#define C_N 400

#define MAXN 30000
#define MAXV 1000000
int a[MAXN+5];
int last[MAXN+5], nxt[MAXN+5];
int last_v[MAXV+5];
int cnt[C_N+5][C_N+5];
int vis[MAXV+5];

int main(){
	int n;
	scanf("%d", &n);

	RESET(last_v, -1);
	for (int i = 0; i < n; ++i)
		nxt[i] = n;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		last[i] = last_v[a[i]];
		if (last[i] >= 0) nxt[last[i]] = i;
		last_v[a[i]] = i;
	}

	for (int i = 0; i*C_SZ+C_SZ-1 < n; ++i) {
		for (int j = i; j*C_SZ+C_SZ-1 < n; ++j) {
			cnt[i][j] = (i == j) ? 0 : cnt[i][j-1];
			for (int k = 0; k < C_SZ; ++k) {
				int idx = j*C_SZ+k;
				if (last[idx] < i*C_SZ) {
					cnt[i][j]++;
				}
			}
		}
	}

	int nq;
	scanf("%d", &nq);
	for (int q = 0; q < nq; ++q) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;

		int ans = 0;
		if (r-C_SZ+1 >= 0 && l+C_SZ-1 < n) {
			int c_lp = (l+C_SZ-1)/C_SZ;
			int c_rp = (r-C_SZ+1)/C_SZ;
			if (c_lp > c_rp) {
				for (int i = l; i <= r; ++i) {
					if (last[i] < l) ++ans;
				}
			}
			else {
				ans = cnt[c_lp][c_rp];
				// get left
				int c_lf = c_lp*C_SZ, c_rf = (c_rp+1)*C_SZ;
				for (int i = c_lf-1; i >= l; --i) {
					if (vis[a[i]]) continue;
					int n_idx = nxt[i];
					if (n_idx >= c_rf) ++ans;
					vis[a[i]] = 1;
				}
				// get right
				for (int i = c_rf; i <= r; ++i) {
					if (vis[a[i]]) continue;
					int l_idx = last[i];
					if (l_idx < c_lf) ++ans;
					vis[a[i]] = 1;
				}
				for (int i = l; i < c_lf; ++i) vis[a[i]] = 0;
				for (int i = c_rf; i <= r; ++i) vis[a[i]] = 0;
			}
		}
		else {
			for (int i = l; i <= r; ++i) {
				if (last[i] < l) ++ans;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

