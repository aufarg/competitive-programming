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

#define MAXN 200

int sqr(int a) { return a * a; }
int dist(pii a, pii b) {
	return max(abs(a.F-b.F), abs(a.S-b.S));
}
int clockwise(pii b, pii a, pii c) {
	// center in a
	pair<ll, ll> dba = MP(a.F-b.F, a.S-b.S);
	pair<ll, ll> dac = MP(c.F-a.F, c.S-a.S);

	return (dba.F*dac.S-dac.F*dba.S) > 0;
}

int main(){
    OPEN("lightsout");
    int n;
    scanf("%d", &n);
    pii p[MAXN+5];
    int len[MAXN+5];
    for (int i = 0; i < n; ++i) {
    	int x,y;
    	scanf("%d%d", &x, &y);
    	p[i] = MP(x,y);
    }
    p[n] = p[0];
    for (int i = 0; i <= n; ++i) {
    	if (!i) len[i] = 0;
    	else len[i] = len[i-1] + dist(p[i], p[i-1]);
    	//printf("%d\n", len[i]);
    }
    int total_len = len[n];
    for (int i = 0; i <= n; ++i) {
    	len[i] = min(len[i], total_len-len[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
    	for (int j = 1; j < n; ++j) {
    		if (i == j) continue;
			int l = 0, dst = 0;
			while (i+l < n && j+l < n) {
				// check angle, pasti 90 derajat jadi tinggal cek cw/ccw
				if (clockwise(p[i+l-1],p[i+l],p[i+l+1]) != clockwise(p[j+l-1],p[j+l],p[j+l+1])) 
					break;
				// travel
				int d1 = dist(p[i+l], p[i+l+1]);
				int d2 = dist(p[j+l], p[j+l+1]);
				dst += d1;
				++l;
				// check distance
				if (d1 != d2) 
					break;
			}
			ans = max(ans, dst + len[i+l] - len[i]);
			//printf("%d %d %d: %d %d %d\n", i, j, l, dst, len[i+l], len[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

