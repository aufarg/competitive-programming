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

#define MAXN 2000
#define MAXV 5000

int a[MAXN+5];
int vis[MAXV+5];
int bit[MAXV+5];


void update(int k, int v) {
	for (; k <= MAXV; k+=k&(-k))
		bit[k] += v;
}

int query(int k) {
	int ret = 0;
	for (; k; k -= k&(-k))
		ret += bit[k];
	return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &a[i]);
    }
    sort(a, a+n);

    map<int, int> pos_sum;
    for (int i = 0; i < n; ++i)
    	for (int j = i+1; j < n; ++j) {
			pos_sum[a[j]-a[i]]++;
    	}

    FORIT(it, pos_sum) {
    	update(it->F, it->S);
    }

	double ans = 0.0;
	FORIT(it1, pos_sum) {
		for (__typeof(pos_sum.begin()) it2 = pos_sum.begin(); it2 != pos_sum.end() && it2->F < it1->F; ++it2) {
			int d = it1->F - it2->F;
			double c1 = (double)it1->S / (double)(n * (n-1) / 2);
			double c2 = (double)it2->S / (double)(n * (n-1) / 2);
			double c3 = (double)query(d-1)/ (double)(n * (n-1) / 2);
			/* printf("%d %d %d\n", it1->F, it2->F, d); */
			/* printf("%d %d\n", it1->S, it2->S); */
			/* printf("%lf %lf %lf\n", c1, c2, c3); */
			ans += c1 * c2 * c3;
		}
	}
	printf("%.9lf\n", ans);
	return 0;
}

