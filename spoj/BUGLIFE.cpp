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

#define MAXN 2000
vector<int> adj[MAXN+5];
int color[MAXN+5];

int DFS(int cur, int len) {
    if (color[cur] != -1)
        return ( (color[cur] + len) % 2 ); 
    color[cur] = len;

    int ret = 0;
    for (int i = 0; i < SZ(adj[cur]); ++i) {
        ret |= DFS(adj[cur][i], len+1);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(false);
    int ntc;
    cin >> ntc;
    for (int itc=1; itc<=ntc; ++itc) {
        int N, M;
        RESET(color, -1);
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) adj[i].clear();
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        int yes = true;
        for (int i = 1; i <= N; ++i) {
            if (color[i] == -1 && DFS(i, 0)) {
                yes = false;
            }
        }
        cout << "Scenario #" << itc << ":" << endl;
        cout << ((yes) ? "No suspicious bugs found!" : "Suspicious bugs found!" ) << endl;
    }
    return 0;
}
