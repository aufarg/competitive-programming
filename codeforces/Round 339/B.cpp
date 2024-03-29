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
    int n;
    scanf("%d", &n);
    int zeros = 0;
    string ans = "1";
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	if (s == "0") {
    		puts("0");
    		return 0;
    	}
    	int beauty = 1;
		int ones = 0;
    	for (int j = SZ(s) - 1; j >= 0; --j) {
    		if (s[j] == '1') ++ones;
    		if (ones > 1 || (s[j] != '1' && s[j] != '0')) beauty = 0;
    	}
    	
    	if (beauty) {
			for (int j = SZ(s) - 1; j >= 0 && s[j] == '0'; --j) {
				++zeros;
			}
		}
		else {
			ans = s;
		}

	}

	cout << ans;
	for (int i = 0; i < zeros; ++i) {
		putchar('0');
	}
	puts("");
	return 0;
}

