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

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "SmilesTheFriendshipUnicorn.cpp"
#include <string>
#include <vector>

#define MAXN 2000
vector<int> edge[MAXN+5];
int vis[MAXN+5];
class SmilesTheFriendshipUnicorn {
	public:
		int dfs(int v, int cnt) {
			if (cnt == 4) return 1;
			vis[v] = 1;
			for (int i = 0; i < (int)edge[v].size(); ++i) {
				int u = edge[v][i];
				if (vis[u]) continue;
				if (dfs(u, cnt+1)) {
					return 1;
				}
			}
			vis[v] = 0;
			return 0;
		}
		string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
			int edge_size = A.size();
			for (int i = 0; i < edge_size; ++i) {
				edge[A[i]].push_back(B[i]);
				edge[B[i]].push_back(A[i]);
			}
			for (int i = 0; i < N; ++i) {
				if (dfs(i, 0)) return "Yay!";
			}
			return ":(";
		}
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
		cout << "Testing SmilesTheFriendshipUnicorn (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456192805;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SmilesTheFriendshipUnicorn _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
				{
					int N = 4;
					int A[] = {0, 0, 1, 2};
					int B[] = {1, 2, 3, 3};
					_expected = ":(";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 1:
				{
					int N = 5;
					int A[] = {0, 1, 2, 3, 1};
					int B[] = {1, 2, 3, 0, 4};
					_expected = "Yay!";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 2:
				{
					int N = 6;
					int A[] = {0, 0, 0, 0, 0};
					int B[] = {1, 2, 3, 4, 5};
					_expected = ":(";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 3:
				{
					int N = 8;
					int A[] = {1, 3, 4, 3, 4, 3, 0, 2};
					int B[] = {7, 7, 7, 4, 6, 5, 4, 7};
					_expected = "Yay!";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 4:
				{
					int N = 7;
					int A[] = {0, 1, 1, 5, 4, 5};
					int B[] = {5, 2, 3, 6, 1, 1};
					_expected = ":(";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 5:
				{
					int N = 42;
					int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
					int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
					_expected = "Yay!";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 6:
				{
					int N = 5;
					int A[] = {0, 0, 1, 1, 1};
					int B[] = {1, 2, 2, 3, 4};
					_expected = ":(";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 7:
				{
					int N = 3;
					int A[] = {0, 1, 1};
					int B[] = {1, 3, 4};
					_expected = ":(";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
			case 8:
				{
					int N = 5;
					int A[] = { 0, 0, 2, 4, 0, 0 };
					int B[] = { 3, 1, 3, 1, 4, 2 };
					_expected = "Yay!";
					_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
				}
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
