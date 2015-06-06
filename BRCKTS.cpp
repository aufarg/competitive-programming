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

#define MAXN 60000
#define INF 10000000

struct SegTree {
    vector<int> origin;
    pair<int, pair<int,int> > node[2*MAXN+5];
    int upnode[2*MAXN+5];
    SegTree(vector<int> nodes) {
        origin = nodes;
        RESET(upnode,0);
        build(1,SZ(origin),1);
    }
    void build(int lf, int rt, int idx) {
        if (lf >= rt) {
            node[idx] = MP(origin[lf-1], MP(lf, rt));
        }
        else {
            build(lf, (lf+rt)/2, idx*2);
            build((lf+rt)/2+1, rt, idx*2+1);
            node[idx] = MP(min(node[idx*2].F, node[idx*2+1].F), MP(lf, rt));
        }
    }
    int query(int lf, int rt, int idx) {
        int tlf = node[idx].S.F;
        int trt = node[idx].S.S;

        int upg = upnode[idx];
        upnode[idx] = 0;

        if (tlf != trt) {
            upnode[idx*2] += upg;
            upnode[idx*2+1] += upg;
        }

        if (lf <= tlf && trt <= rt) {
           return node[idx].F += upg;
        }
        else if (trt < lf || tlf > rt) {
            node[idx].F += upg;
            return INF;
        }
        else {
            int tl = query(lf, rt, idx*2);
            int tr = query(lf, rt, idx*2+1); 
            node[idx].F = min(node[idx*2].F, node[idx*2+1].F);
            return min(tr,tl);
        }
    }
    void update(int lf, int rt, int idx, int plus) {
        int tlf = node[idx].S.F;
        int trt = node[idx].S.S;

        int upg = upnode[idx];
        upnode[idx] = 0;

        if (tlf != trt) {
            upnode[idx*2] += upg;
            upnode[idx*2+1] += upg;
        }

        if (lf <= tlf && trt <= rt) {
            node[idx].F += upg + plus;
            if (tlf != trt) {
                upnode[idx*2] += plus;
                upnode[idx*2+1] += plus;
            }
        }
        else if (trt < lf || tlf > rt) {
            node[idx].F += upg;
        }
        else {
            update(lf, rt, idx*2, plus);
            update(lf, rt, idx*2+1, plus);
            node[idx].F = min(node[idx*2].F, node[idx*2+1].F);
        }
    }
};

int a[MAXN+5];

int main(){
    for (int itc = 1; itc <= 10; ++itc) {
        printf("Test %d:\n", itc);
        int n, m;
        string s;
        scanf("%d", &n);
        cin >> s;
        vector<int> sum;
        for (int i = 1; i <= n; ++i) {
            a[i] = (s[i-1] == '(') ? 1 : -1;
            if (i == 1) sum.PB(a[i]);
            else sum.PB(sum.back() + a[i]);
        }

        scanf("%d", &m);
        SegTree segTree(sum);
        int tsum = sum.back();
        for (int i = 0; i < m; ++i) {
            int k;
            scanf("%d", &k);
            if (k == 0) {
                int q = segTree.query(1,n,1);
                if (q >= 0 && tsum == 0) puts("YES");
                else puts("NO");
            }
            else {
                tsum += -2*a[k];
                segTree.update(k, n, 1, -2*a[k]);
                a[k] = -a[k];
            }
        }
    }
    return 0;
}

