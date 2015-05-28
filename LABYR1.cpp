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
#define MAXR 1000
#define MAXC 1000

int R,C;
int ntc, ans;
char a[MAXR+5][MAXC+5];
int vis[MAXR+5][MAXC+5];

pair<int,pair<int,int> > DFS(int row, int col) {
    pair<int,pair<int,int> > ret = MP(0, MP(row, col));
    if (row < 0 || col < 0 || row >= R || col >= C) 
        return ret;
    if (a[row][col] == '#' || vis[row][col]) return ret;
    vis[row][col] = 1;
    static int dr[] = { 0, 0, 1, -1 };
    static int dc[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; ++i) {
        pair<int,pair<int,int> > tmp = DFS(row + dr[i], col + dc[i]);
        if (tmp.F > ret.F) 
            ret = tmp;
    }
    ++ret.F;
    return ret;
}

int main(){
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d%d", &C, &R);
        int sr, sc;
        RESET(vis,0);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                scanf(" %c", &a[i][j]);
                if (a[i][j] == '.') {
                    sr = i;
                    sc = j;
                    
                }
            }
        }
        pair<int, int> ps = DFS(sr, sc).S;
        RESET(vis,0);
        printf("Maximum rope length is %d.\n", DFS(ps.F, ps.S).F-1);
    }
    return 0;
}

