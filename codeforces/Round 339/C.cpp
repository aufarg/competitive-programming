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
typedef pair<ll,ll> pll;
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

double sqr(double a) { return a * a; }

const double PI = acos(-1);

double segdist(pll s1, pll s2, pll p)
{
	double dX = s2.F - s1.F;
	double dY = s2.S - s1.S;
	if ((dX == 0) && (dY == 0))
	{
		dX = p.F - s1.F;
		dY = p.S - s1.S;
		return sqrt(dX * dX + dY * dY);
	}

	double t = ((p.F - s1.F) * dX + (p.S - s1.S) * dY) / (dX * dX + dY * dY);

	if (t < 0) {
		dX = p.F - s1.F;
		dY = p.S - s1.S;
	}
	else if (t > 1) {
		dX = p.F - s2.F;
		dY = p.S - s2.S;
	}
	else {
		dX = p.F - (s1.F + t * dX);
		dY = p.S - (s1.S + t * dY);
	}

	return sqr(dX) + sqr(dY);
}

#define MAXN 100000

int main(){
	int n;
	pll p;
	scanf("%d", &n);
	cin >> p.F >> p.S;
	double maxr = 0, minr = 1e14;
	pii pts[MAXN+5];
	for (int i = 0; i < n; ++i) {
		cin >> pts[i].F >> pts[i].S;
	}
	for (int i = 0; i < n; ++i) {
		double dist = sqr(pts[i].F-p.F) + sqr(pts[i].S-p.S);
		double segd = segdist(pts[i], pts[(i+1)%n], p);

		maxr = max(maxr, dist);
		maxr = max(maxr, segd);
		minr = min(minr, dist);
		minr = min(minr, segd);
	}

	double outar = PI * maxr;
	double inar = PI * minr;
	//printf("%lf %lf\n", maxr, minr);
	printf("%.7lf\n", outar - inar);
	return 0;
}

