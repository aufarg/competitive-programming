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
    map<string, int> timezone;
    for (int i = 0; i < n; ++i) {
    	char name[20];
    	int offset;
    	scanf("%s GMT%d", name, &offset);
    	string s = name;
    	timezone[s] = offset;
    	
    }
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
    	char input[100];
    	char name_a[20], name_b[20];
    	int hh_a, mm_a, hh_b, mm_b, off = 0;
    	scanf("\n%[^\n]", input);
    	sscanf(input, "%s%d:%d%s%d:%d%d", name_a, &hh_a, &mm_a, name_b, &hh_b, &mm_b, &off);


    	string s_a = name_a, s_b = name_b;
    	int hour = hh_b - hh_a + 24 * off + timezone[name_a] - timezone[name_b];
    	int min = mm_b - mm_a;

    	if (min < 0) {
    		min += 60;
    		hour--;
    	}
    	printf("Case #%d: %d hours and %d minutes\n", itc, hour, min);

    }
    return 0;
}
