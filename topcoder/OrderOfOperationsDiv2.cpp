/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MP make_pair
#define PB push_back

#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "OrderOfOperationsDiv2.cpp"
#include <string>
#include <vector>

int vis[(1<<21)+5], memo[(1<<21)+5];
class OrderOfOperationsDiv2 {
	public:
	int n, m;
	vector<string> s;
	int dp(int mask) {
		if (vis[mask]) return memo[mask];
		int mem[24];
		RESET(mem, 0);
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1<<i))
				for (int j = 0; j < m; ++j)
					if (s[i][j] == '1')
						mem[j] = 1;
		}
		int first = 1;
		for (int i = 0; i < n; ++i) {
			if (mask & (1<<i)) continue;
			int cost = 0;
			for (int j = 0; j < m; ++j) 
				if (mem[j] == 0 && s[i][j] == '1')
					++cost;

			if (first) {
				first = 0;
				ret = cost*cost + dp(mask|(1<<i));
			}
			else
				ret = min(ret, cost*cost + dp(mask|(1<<i)));
		}
		vis[mask] = 1; memo[mask] = ret;
		return ret;
	}
	int minTime(vector <string> s) {
		this->n = SZ(s);
		this->m = SZ(s[0]);
		this->s = s;
		return dp(0);
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
		cout << "Testing OrderOfOperationsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443345791;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OrderOfOperationsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {
				              "111",
				              "001",
				              "010"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 1:
			{
				string s[] = {
				              "11101",
				              "00111",
				              "10101",
				              "00000",
				              "11000"
				             };
				_expected = 9;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 2:
			{
				string s[] = {
				               "11111111111111111111"
				             };
				_expected = 400;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 3:
			{
				string s[] = {
				               "1000",
				               "1100",
				               "1110"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 4:
			{
				string s[] = {
				               "111",
				               "111",
				               "110",
				               "100"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			/*case 5:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
