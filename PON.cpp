/* kucingimbalance */
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

#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)

//type definitions
typedef long long ll;
typedef unsigned long long ull;

//abbreviations
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

/* -------------- end of kucingimbalance's template -------------- */

int num[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ull mod_mul(ull base, ull times, ull mod) {
		if (times == 0) return 0;
		ull ret = mod_mul(base, times/2, mod);
		ret = (ret + ret) % mod;
		if (times%2) return (ret + base) % mod;
		else return ret;
	}
	ull mod_exp(ull base, ull power, ull mod) {
		if (power == 0) return 1;
		ull ret = mod_exp(base, power/2, mod);
		ret = mod_mul(ret, ret, mod);
		if (power%2) return mod_mul(ret, base, mod);
		else return ret;
	}

int check(ull n) {
	if (n == 2 || n == 3) return 1;

	ull d = (n-1);
	ull two = 0;
	while (d % 2 == 0) {
		d /= 2;
		++two;
	}

	for (int i = 0; i < 9; ++i) {
		ull a = num[i];
		if (a > n-2) break;
		ull x = mod_exp(a, d, n);
		if (x == 1 || x == n-1) continue;
		int cont = 0;
		int s = two-1;
		for (; s > 0 && x != n-1 && x != 1; --s) {
			x = mod_mul(x, x, n);
			if (x == 1) return 0;
			if (x == n-1) {
				cont = true;
			}
		}
		if (cont) continue;
		return 0;
	}
	return  1;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		ull n;
		scanf("%llu", &n);
		if (check(n))
			puts("YES");
		else 
			puts("NO");
	}
}