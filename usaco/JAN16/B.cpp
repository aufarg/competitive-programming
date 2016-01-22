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
#define MAXN 1000
#define MAXM 1000
#define INF 1000000000

int N, M;
vector<pii> f, b;
string fp, bp;

int vis[MAXN+5][MAXM+5];
int memo[MAXN+5][MAXM+5];

int sqr(int a) { return a*a; }
int dist(pii a, pii b) {
	return sqr(a.F-b.F)+sqr(a.S-b.S);
}

int dp(int fidx, int bidx) {
	if (fidx >= N && bidx >= M) return 0;
	int &ret = memo[fidx][bidx];
	if (vis[fidx][bidx]) return ret;
	ret = INF;
	int sqd;
	// both go
	if (fidx < N && bidx < M) {
		sqd = dist(f[fidx+1], b[bidx+1]);
		ret = min(ret, dp(fidx+1, bidx+1) + sqd);
	}
	// farmer
	if (fidx < N) {
		sqd = dist(f[fidx+1], b[bidx]);
		ret = min(ret, dp(fidx+1, bidx) + sqd);
	}
	// bessie
	if (bidx < M) {
		sqd = dist(f[fidx], b[bidx+1]);
		ret = min(ret, dp(fidx, bidx+1) + sqd);
	}
	vis[fidx][bidx] = 1;
	return ret;
}

int main(){
	OPEN("radio");
	scanf("%d%d", &N, &M);
	int fx, fy, bx, by;
	scanf("%d%d", &fx, &fy);
	scanf("%d%d", &bx, &by);
	f.PB(MP(fx,fy)); b.PB(MP(bx,by));
	cin >> fp >> bp;
	int dr[] = { 0, 0, 1, -1 };
	int dc[] = { 1, -1, 0, 0 };
	for (int i = 0; i < N; ++i) {
		int dir;
		switch(fp[i]) {
			case 'N': dir = 0; break;
			case 'S': dir = 1; break;
			case 'E': dir = 2; break;
			case 'W': dir = 3; break;
		}
		pii prev = f.back();
		prev.F += dr[dir]; prev.S += dc[dir];
		f.PB(prev);
	}
	for (int i = 0; i < M; ++i) {
		int dir;
		switch(bp[i]) {
			case 'N': dir = 0; break;
			case 'S': dir = 1; break;
			case 'E': dir = 2; break;
			case 'W': dir = 3; break;
		}
		pii prev = b.back();
		prev.F += dr[dir]; prev.S += dc[dir];
		b.PB(prev);
	}
	printf("%d\n", dp(0,0));
	return 0;
}

