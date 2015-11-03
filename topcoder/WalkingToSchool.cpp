/* DELAPAN.3gp */
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define MN(a,b) a = min(a,b)

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "WalkingToSchool.cpp"
#include <string>
#include <vector>

#define MAXN 2000
#define MAXSTEP 2000

int cvis[MAXN+5][MAXSTEP+5];

class WalkingToSchool {
	public:
	string canWalkExactly(int N, vector <int> from, vector <int> to) {
		int M = SZ(from);
		RESET(dfs_index, 0);
		RESET(vis, 0);
		for (int i = 0; i < M; ++i)
			edge[from[i]].PB(to[i]);
		
		scc(0);
		RESET(in_com, 0);
		for (int i = 0; i < SZ(comp); ++i) {
			in_com[comp[i]] = 1;
		}
		if (!in_com[1]) return "Chores";
		int g = 0;
		RESET(cvis, 0);
		RESET(vis, -1);
		queue<pair<int,int> > Q;
		Q.push(MP(0,0));
		while (!Q.empty()) {
			int v = Q.front().F, step = Q.front().S;
			Q.pop();
			if (cvis[v][step] || step > N) continue;
			if (vis[v] >= 0) {
				static int first = 1;
				g = (first) ? step-vis[v] : gcd(g, step-vis[v]);
				//cout << v << ' ' << step << ' ' <<  vis[v] << endl;
				first = 0;
			}
			else vis[v] = step;
			cvis[v][step] = 1;
			for (int i = 0; i < SZ(edge[v]); ++i) {
				int u = edge[v][i];
				if (in_com[u]) Q.push(MP(u,step+1));
			}
		}
		return (g == 1) ? "Freedom" : "Chores";
	}
	int gcd(int a, int b) { return (b) ? gcd(b, a % b) : a; }
	void scc(int v) {
		static int index = 1;
		dfs_low[v] = dfs_index[v] = index;
		st.push(v);
		vis[v] = 1;
		++index;

		for (int i = 0; i < SZ(edge[v]); ++i) {
			int u = edge[v][i];
			if (!dfs_index[u]) {
				scc(u);
				MN(dfs_low[v], dfs_low[u]);
			}
			else if (vis[u]) {
				MN(dfs_low[v], dfs_low[u]);
			}
		}

		if (dfs_low[v] == dfs_index[v]) {
			int u;
			do {
				u = st.top();
				st.pop();
				vis[u] = 0;
				if (v == 0) comp.PB(u);
			} while (u != v);
		}
	}
	int dfs_index[MAXN+5], dfs_low[MAXN+5];
	int vis[MAXN+5];
	int in_com[MAXN+5];
	vector<int> edge[MAXN+5];
	stack<int> st;
	vector<int> comp;
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing WalkingToSchool (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443362985;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WalkingToSchool _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int from[] = {0, 1};
				int to[] = {1, 0};
				_expected = "Chores";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 3;
				int from[] = {0, 1, 1, 2};
				int to[] = {1, 0, 2, 0};
				_expected = "Freedom";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 4;
				int from[] = {0, 2, 2, 3, 0};
				int to[] = {2, 0, 3, 0, 1};
				_expected = "Chores";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 10;
				int from[] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9};
				int to[] = {4, 5, 6, 7, 9, 4, 6, 0, 1, 3, 8, 4, 6, 1, 4, 8, 1, 7, 8, 1, 4, 2, 5, 6, 8};
				_expected = "Chores";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 8;
				int from[] = {0, 1, 4, 6, 7, 5, 2, 3, 0};
				int to[] = {1, 4, 6, 7, 5, 2, 3, 0, 7};
				_expected = "Freedom";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 2000;
				int from[] = {};
				int to[] = {};
				_expected = "Chores";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 5;
				int from[] = {0, 2, 3, 0, 4, 1};
				int to[] = {2, 3, 2, 4, 1, 0};
				_expected = "Chores";
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}
			/*case 7:
			{
				int N = ;
				int from[] = ;
				int to[] = ;
				_expected = ;
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int from[] = ;
				int to[] = ;
				_expected = ;
				_received = _obj.canWalkExactly(N, vector <int>(from, from+sizeof(from)/sizeof(int)), vector <int>(to, to+sizeof(to)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
