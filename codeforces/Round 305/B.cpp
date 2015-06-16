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

#define MAXN 200000

int a[MAXN+5];
int tmp[MAXN+5];
int ans[MAXN+5];

map<int, vector<int> > ori;

int main(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        tmp[i] = a[i];
        ori[a[i]].push_back(i);
    }
    sort(tmp, tmp+n);
    set<int> idx;
    for (int i = 0; i < n; ++i) {
        if (i+1 < n && tmp[i] == tmp[i+1]) continue;

        int yay = 0;
        vector<int> idxlist = ori[tmp[i]];
        for (int j = 0; j < SZ(idxlist); ++j) {
            set<int>::iterator lf = (idx.lower_bound(idxlist[j]);
            set<int>::iterator rt = (idx.upper_bound(idxlist[j]));
            if (lf == idx.end()) {
                lf = 0;
            }
            else {
                lf = *lf + 1;
            }
            if (rt == idx.end()) {
                rt = n-1;
            }
            else {
                rt = idx[rt] - 1;
            }
            MX(yay, rt-lf+1);
        }
        for (int j = 0; j < SZ(idxlist); ++j) {
            idx.insert(idxlist[j]);
        }
        ans[yay] = tmp[i];
    }
    for (int i = 0; i+1 < n; ++i) {
        MX(a[i+1], a[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        printf("%d\n", a[i]);
    }

    return 0;
}

