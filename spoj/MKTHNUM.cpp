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

#define MAXN 100000
int n, m;
int cnt;
int a[MAXN+5];
int mapped[MAXN+5];
map<int, int> a_map, rev_map;

struct node {
	int l,r; 
	vector<int> elmnts;
	node *lchild, *rchild;
};

void build_tree(node *cur_node) {
	int l = cur_node->l, r = cur_node->r;
	if (cur_node->l == cur_node->r) {
		cur_node->elmnts.PB(mapped[l]);
		return;
	}
	
	// lch sama rch placeholder aja
	node *lch = cur_node->lchild = (node *)malloc(sizeof(node));
	node *rch = cur_node->rchild = (node *)malloc(sizeof(node));

	lch->l = l; lch->r = (l+r)/2;
	rch->l = (l+r)/2+1; rch->r = r;

	build_tree(lch); build_tree(rch);
	vector<int> *ret = &cur_node->elmnts;
	int idl = 0, idr = 0;
	while (idl < SZ(lch->elmnts) && idr < SZ(rch->elmnts)) {
		if (lch->elmnts[idl] < rch->elmnts[idr]) {
			ret->PB(lch->elmnts[idl]);
		}
		else {
			ret->PB(rch->elmnts[idr]);
		}
	}
	return;
}


int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mapped[i] = a[i];
		a_map[a[i]] = 1;
	}

	FORIT(it, a_map) {
		it->second = ++cnt;
		rev_map[it->second] = it->first;
	}

	node root;
	root.l = 1; root.r = n;
	build_tree(&root);

	return 0;
}

