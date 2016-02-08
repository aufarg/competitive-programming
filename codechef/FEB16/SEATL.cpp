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
#define MAXA 1000000
pair<int, set<int> > cbest[MAXA+5];
int access[MAXA+5];

int main(){
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
    	int n, m;
    	scanf("%d%d", &n, &m);
    	vector<vector<int> > matrix;
    	for (int i = 0; i < n; ++i)  {
    		matrix.PB(vector<int>());
    		for (int j = 0; j < m; ++j)  {
    			int a;
    			scanf("%d", &a);
    			matrix[i].PB(a);
    		}
    	}

    	for (int j = 0; j < m; ++j) {
    		map<int, int> cur;
    		for (int i = 0; i < n; ++i) 
    			cur[matrix[i][j]]++;
    		FORIT(it, cur) {
    			if (access[it->F] > ntc || it->S > cbest[it->F].F) {
    				cbest[it->F].F = it->S;
    				cbest[it->F].S.clear();
					cbest[it->F].S.insert(j);
    			}
				if (it->S == cbest[it->F].F) {
					cbest[it->F].F = it->S;
					cbest[it->F].S.insert(j);
				}
				access[it->F] = ntc;
    		}
    	}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			map<int, int> cur, cnt;
			for (int j = 0; j < m; ++j) {
				if (access[matrix[i][j]] > ntc) continue;
				cur[matrix[i][j]]++;
				if (EXIST(j, cbest[matrix[i][j]].S)) {
					cnt[matrix[i][j]]++;
				}
			}

			FORIT(it ,cur) {
				int val = it->F;
				if (cnt[val] < SZ(cbest[val].S)) {
					ans = max(ans, cbest[val].F+it->S);
				}
				else {
					ans = max(ans, cbest[val].F+it->S-1);
				}
			}
		}

		printf("%d\n", ans);
    }
    return 0;
}

