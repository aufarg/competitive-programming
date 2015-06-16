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
    cin.sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;
    set<int> hset, wset;
    hset.insert(0); hset.insert(h);
    wset.insert(0); wset.insert(w);
    priority_queue<pair<int, pair<int,int> > > hp, wp;
    hp.push(MP(h, MP(0, h)));
    wp.push(MP(w, MP(0, w)));
    for (int i = 0; i < n; ++i) {
        char c; int loc;
        cin >> c >> loc;
        if (c == 'H') {
            hset.insert(loc);
            set<int>::iterator it = hset.find(loc);
            int left, right;
            left = *(--it);
            ++it;
            right = *(++it);
            pair<int, pair<int,int> > distpair;
            distpair = MP(loc - left, MP(left, loc));
            hp.push(distpair);   
            distpair = MP(right - loc, MP(loc, right));
            hp.push(distpair);
        }
        else {
            wset.insert(loc); 
            set<int>::iterator it = wset.find(loc);
            int left, right;
            left = *(--it);
            ++it;
            right = *(++it);
            pair<int, pair<int,int> > distpair;
            distpair = MP(loc - left, MP(left, loc));
            wp.push(distpair);   
            distpair = MP(right - loc, MP(loc, right));
            wp.push(distpair);

        }
        while (!hp.empty()) {
            pair<int, pair<int,int> > top;
            top = hp.top();
            set<int>::iterator it = hset.find(top.S.F);
            ++it;
            if (it == hset.find(top.S.S)) break;
            hp.pop();
        }
        while (!wp.empty()) {
            pair<int, pair<int,int> > top;
            top = wp.top();
            set<int>::iterator it = wset.find(top.S.F);
            ++it;
            if (it == wset.find(top.S.S)) break;
            wp.pop();
        }
        cout << (ll)(hp.top().F) * (ll)(wp.top().F) << endl;
    }
    return 0;
}
