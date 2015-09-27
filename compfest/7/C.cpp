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
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 0; itc < ntc; ++itc) {
		string s;
		cin >> s;
		int n = SZ(s);
		int sum = 0;
		int last = 1;
		for (int i = 0; i < n; ++i) {
			if ( (i % 2 == 0 && s[i] == '(') || (i % 2 == 1 && s[i] == ')') ) ;
			else last = 0;
		}
		if (last) {
			puts("TIDAK ADA");
			continue;
		}
		int idx = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') {
				if (sum) idx = i;
				++sum;
			}
			else --sum;
		}
		sum = 0;
		for (int j = 0; j < n; ++j) {
			if (j < idx) {
				putchar(s[j]);
				if (s[j] == '(') ++sum;
				else --sum;
			}
			else if (j > idx) {
				int remaining = n-j;
				if (remaining == sum) {
					putchar(')');	
					--sum;
				}
				else {
					putchar('(');
					++sum;
				}
			}
			else {
				putchar(')'); 
				--sum;
			}
		}
		puts("");
	}	
	return 0;
}
