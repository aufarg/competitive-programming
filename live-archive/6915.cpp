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

#define MAXN 1000000
double a[MAXN+5];
double sum[MAXN+5];

int main(){
	cin.sync_with_stdio(false);
	int NTC;
	cin >> NTC;
	for (int itc = 1; itc <= NTC; ++itc) {
		int N, M;
		string S;

		cin >> N >> M >> S;
		a[1] = 0;
		for (int i = 1; i <= N; ++i) {
			if (S[i-1] == '/') {
				a[i] += 0.5;
				a[i+1] = ceil(a[i]);
			}
			if (S[i-1] == '\\') {
				a[i] -= 0.5;
				a[i+1] = floor(a[i]);
			}
			if (S[i-1] == '_') {
				a[i+1] = a[i];
			}

			sum[i] = sum[i-1] + a[i];

		}
		deque<pair<double, int> > dq;
		for (int i = 1; i <= M; ++i) {
			while (!dq.empty() && dq.back().F >= a[i]) {
				dq.pop_back();
			}
			dq.push_back(MP(a[i], i));
		}


		double ans = sum[M] - (floor(dq.front().F) * M);

		for (int i = M+1; i <= N; ++i) {
			if (dq.front().S < i-M+1) {
				dq.pop_front();
			}
			while (!dq.empty() && dq.back().F >= a[i]) {
				dq.pop_back();
			}
			dq.push_back(MP(a[i], i));
			double tans = (sum[i] - sum[i-M]) - (floor(dq.front().F) * M);
			MN(ans, tans);
		}

		printf("Case #%d: %.1lf\n", itc, ans);
	}
	return 0;
}

