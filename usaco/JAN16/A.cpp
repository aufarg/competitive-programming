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

#define MAXN 50000

int n;
int ar[MAXN+5];
int nleft[MAXN+5], nright[MAXN+5];

int main(){
    OPEN("angry");
    scanf("%d", &n);

    double l = 0.0, r = 1e9;
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &ar[i]);
    }
    sort(ar, ar+n);

    int till, nxt;
    for (int i = 0; i < n; ++i) {
    	if (i) {
			if (ar[i] > till) {
				if (nleft[i-1]+1 > ar[i]-ar[i-1]) {
					nxt = nxt+1;
					till = ar[i-1]+nxt;
					nleft[i] = nxt;
				}
				else {
					nxt = ar[i]-ar[i-1]+1;
					till = ar[i]+nxt;
					nleft[i] = nxt-1;
				}

			}
			else nleft[i] = nxt;
		}
		else nleft[i] = 0, till = ar[i], nxt = 1;
		//printf("%d ", nleft[i]);
	}
	//puts("");
	for (int i = n-1; i >= 0; --i) {
		if (i != n-1) {
			if (ar[i] < till) {
				if (nright[i+1]+1 > ar[i+1]-ar[i]) {
					nxt = nxt+1;
					till = ar[i+1]-nxt;
					nright[i] = nxt;
				}
				else {
					nxt = ar[i+1]-ar[i]+1;
					till = ar[i]-nxt;
					nright[i] = nxt-1;
				}
			}
			else nright[i] = nxt;
		}
		else nright[i] = 0, till = ar[i], nxt = 1;
		//printf("%d ", nright[i]);
	}
	//puts("");

	for (int bs = 0; bs < 100; ++bs) {
		double mid = (l+r)/2;
		int far = 0;
		int can = 0;
		for (int i = 0; i < n && !can; ++i) {
			while (far < n && ar[far]-ar[i] <= 2*mid) ++far;
			if (nleft[i] <= mid-1.0 && nright[far-1] <= mid-1.0) can = 1;
		}
		if (can) r = mid;
		else l = mid;
	}

	printf("%.1lf\n", (l+r)/2);

	return 0;
}

