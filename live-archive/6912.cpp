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

#define MAXP 1000
#define MAXK 1000
#define MAXN 1000

int main(){
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
    	int n, k;
    	int pr[MAXK+5];
    	scanf("%d%d", &n, &k);
    	for (int i = 0; i < k; ++i) {
    		scanf("%d", &pr[i]);
    	}
    	sort(pr, pr+k);
    	int br_size = 0;
    	for (; br_size < k && pr[br_size] < 34; ++br_size);

    	int ans = 0;
		int on[MAXN+5];
    	for (int b = 0; b < (1 << br_size); ++b) { // 1000
    		int tmp = 0;
    		RESET(on, 0);
    		vector<pii> pre;

    		for (int c = 0; c < br_size; ++c) // 10
    			if (b & (1<<c)) {
    				for (int i = pr[c]; i <= n; i += pr[c]) { // 300~
						on[i] = !on[i];
						if (on[i]) ++tmp;
						else --tmp;
					}
					int sz_pre = SZ(pre);
					for (int i = 0; i < sz_pre; ++i)
						if (pre[i].F * pr[c] < 34)
							pre.PB(MP(pre[i].F * pr[c], pre[i].S+1));
					pre.PB(MP(pr[c],1));
    			}

			for (int c = br_size; c < k; ++c) {
				int ttmp = n / pr[c];
				for (int d = 0; d < SZ(pre); ++d) {
					int num = pr[c] * pre[d].F;
					if (pre[d].S % 2) {
						ttmp -= n / num;
					}
					else {
						ttmp += n / num;
					}
				}
				if (ttmp > 0) tmp += ttmp;
			}

			MX(ans, tmp);
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	return 0;
}

