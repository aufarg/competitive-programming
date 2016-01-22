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

#define INF 100000001

bool cmp(const pair<pii,int> &a, const pair<pii, int> &b) {
	if (a.F.F == b.F.F) 
		return a.F.S < b.F.S;
	return a.F.F < b.F.F;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<pii,int> > vertical, horizontal;
    for (int i = 0; i < n; ++i) {
    	int x1, y1, x2, y2;
    	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    	pair<pii, int> start = MP(MP(x1,y1), i);
    	pair<pii, int> end = MP(MP(x2,y2), i);
    	if (x1 == x2) {
			vertical.PB(start);
			vertical.PB(end);
    	}
    	if (y1 == y2) {
			horizontal.PB(start);
			horizontal.PB(end);
    	}
    }

    sort(ALL(horizontal), cmp);
    sort(ALL(vertical), cmp);

    ll ans = 0;
    int vertptr = 0;
    map<int, set<int> > blocks;
    map<int, int> lasts;
    set<int> rows;
    for (int i = 0; i < SZ(horizontal); ++i) {
		pii point = horizontal[i].F;
		int index = horizontal[i].S;

		int row = point.S;
		int x = point.F; 
		if (EXIST(index, blocks[row])) {
			// remove
			while (vertptr < SZ(vertical) && vertical[vertptr].F.F <= x) {
				set<int> indexes;
				indexes.insert(vertical[vertptr].S);
				int last = vertical[vertptr].F.S - 1;
				++vertptr;
				assert(vertptr < SZ(vertical));
				while (vertptr < SZ(vertical) && vertical[vertptr].F.F == vertical[vertptr-1].F.F) {
					int vindex = vertical[vertptr].S;
					int y = vertical[vertptr].F.S;
					if (EXIST(vindex, indexes)) {
						ans += y - last;
						last = y;
						indexes.erase(vindex);
					}
					else {
						if (SZ(indexes) > 0) {
							ans += y - last;
							last = y;
						}
						else {
							last = y - 1;
						}
						indexes.insert(vindex);
					}
					++vertptr;
				} 
			}
			
			//ans -= SZ(rows);
			printf("%d\n", SZ(rows));

			ans += x - lasts[row];
			blocks[row].erase(index);
			if (SZ(blocks[row]) == 0) {
				rows.erase(row);
			}
			lasts[row] = x;
		}
		else {
			// add
			if (EXIST(row, rows)) {
				ans += x - lasts[row];
				lasts[row] = x;
			}
			else {
				lasts[row] = x - 1;
			}
			blocks[row].insert(index);
			rows.insert(row);

			while (vertptr < SZ(vertical) && vertical[vertptr].F.F <= x) {
				set<int> indexes;
				indexes.insert(vertical[vertptr].S);
				int last = vertical[vertptr].F.S - 1;
				++vertptr;
				assert(vertptr < SZ(vertical));
				while (vertptr < SZ(vertical) && vertical[vertptr].F.F == vertical[vertptr-1].F.F) {
					int vindex = vertical[vertptr].S;
					int y = vertical[vertptr].F.S;
					if (EXIST(vindex, indexes)) {
						ans += y - last + 1;
						last = y;
						indexes.erase(vindex);
					}
					else {
						if (SZ(indexes) > 0) {
							ans += y - last + 1;
							last = y;
						}
						else {
							last = y - 1;
						}
						indexes.insert(vindex);
					}
				} 
			}

			//ans -= SZ(rows);

		}

	}

	cout << ans << endl;

	return 0;
}

