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
#define F first
#define S second
#define MP make_pair
#define PB push_back

//macros
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

int in[MAXN+5];
int out[MAXN+5];
int vis[MAXN+5][MAXN+5];
int ar[MAXN+5];
map<string, int> id;

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (!id[s]) 
			id[s] = ++cnt;
		ar[i] = id[s];
	}

	for (int i = 0; i < n-1; ++i) {
		int now = ar[i];
		int next = ar[i+1];
		if (!vis[now][next]) {
			++in[next];
			++out[now];
			vis[now][next] = 1;
		}
	}
	if (!vis[ar[n-1]][ar[0]]) {
		++in[ar[0]];
		++out[ar[n-1]];
	}

	int center = 0;
	int ans = 1;
	for (int i = 1; i <= cnt; ++i) {
		if (in[i] != 1 || out[i] != 1) {
			if (in[i] == 2 && out[i] == 2) {
				++center;
			}
			else {
				ans = 0;
			}
		}
	}
	if (center != 1) ans = 0;
	if (ans) {
		cout << "Rute Delapan" << endl;
	}
	else {
		cout << "Bukan Rute Delapan" << endl;
	}

	return 0;
}



