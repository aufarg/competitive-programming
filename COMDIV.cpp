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
int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a % b);
}

#define MAXN 1000000
int nprime[MAXN+5];
int fact[MAXN+5];

int main(){
    int NTC;
    for (int i = 2; i*i <= MAXN; ++i) {
        if (!nprime[i]) {
            int t = i * i;
            while (t <= MAXN) {
                nprime[t] = i;
                t += i;
            }
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (!nprime[i])
            nprime[i] = i;
    }
    for (int i = 2; i <= MAXN; ++i) {
        fact[i] = 1;
        int t = i;
        while (t > 1) {
            int base = nprime[t], tmp = 0;
            while (t % base == 0) {
                ++tmp;
                t /= base;
            }
            fact[i] *= (tmp+1);
        }
    }
    fact[1] = 1;
    scanf("%d", &NTC);
    while (NTC--) {
        int A, B;
        scanf("%d%d", &A, &B);
        int g = gcd(A,B);
        printf("%d\n", fact[g]);
    }
    return 0;
}
