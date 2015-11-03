/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MP make_pair
#define PB push_back

#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define MX(a,b) a = max((a),(b));

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "ShopPositions.cpp"
#include <string>
#include <vector>
class ShopPositions {
	public:
	int maxProfit(int n, int m, vector <int> c) {
		this->n = n;
		this->m = m;
		this->c = c;
		int ans;
		RESET(vis, 0);
		for (int i = 0; i <= m; ++i)	
			if (i == 0) ans = dp(0,0,i);
			else MX(ans, dp(0,0,i));
		return ans;
	}
	int n, m;
	vector<int> c;
	int vis[35][35][35], memo[35][35][35];
	int dp(int n, int prev, int cur) {
		if (n+1 == this->n) return cur*c[n*3*this->m+prev+cur-1];
		if (vis[n][prev][cur]) return memo[n][prev][cur];
		int ret;
		for (int i = 0; i <= this->m; ++i) {
			int cost = c[n*3*this->m+prev+cur+i-1];
			if (i == 0) ret = dp(n+1, cur, i) + cur * cost;			
			else MX(ret, dp(n+1, cur, i) + cur * cost);
		}
		vis[n][prev][cur] = 1; memo[n][prev][cur] = ret;
		return ret;
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
		cout << "Testing ShopPositions (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443347575;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ShopPositions _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int m = 5;
				int c[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1};
				_expected = 300;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 1;
				int m = 5;
				int c[] = {1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 1000;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int m = 1;
				int c[] = {
				            7,6,1,
				            10,4,1,
				            7,6,3
				          };
				_expected = 14;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 2;
				int m = 2;
				int c[] = {
				           12,11,10,9,8,7,
				           6,5,4,3,2,1
				          };
				_expected = 24;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 3;
				int c[] = {
				            30,28,25,15,14,10,5,4,2,
				            50,40,30,28,17,13,8,6,3,
				            45,26,14,14,13,13,2,1,1
				          };
				_expected = 127;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.maxProfit(n, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
