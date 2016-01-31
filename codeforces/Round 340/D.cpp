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

int main(){
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	// check if 1 line will do
	if (x1 == x2 && x2 == x3) {
		puts("1");
		return 0;
	}

	if (y1 == y2 && y2 == y3) {
		puts("1");
		return 0;
	}

	if ((x1 == x2 && (y3 <= min(y1, y2) || y3 >= max(y1, y2))) || 
			(x2 == x3 && (y1 <= min(y2, y3) || y1 >= max(y2, y3))) || 
			(x1 == x3 && (y2 <= min(y1, y3) || y2 >= max(y1, y3)))
			) {
		puts("2");
		return 0;
	}

	if ((y1 == y2 && (x3 <= min(x1, x2) || x3 >= max(x1, x2))) || 
			(y2 == y3 && (x1 <= min(x2, x3) || x1 >= max(x2, x3))) || 
			(y1 == y3 && (x2 <= min(x1, x3) || x2 >= max(x1, x3)))) {
		puts("2");
		return 0;
	}

	puts("3");
    return 0;
}

