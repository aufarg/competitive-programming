/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#define PB push_back

#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "IsItASquare.cpp"
#include <string>
#include <vector>

int sqr(int a) { return a*a; }
class IsItASquare {
	public:
	string isSquare(vector <int> x, vector <int> y) {
		bool square = true;
		for (int i = 0; i < SZ(x); ++i) {
			vector<int> dist;
			for (int j = 0; j < SZ(x); ++j) {
				if (i != j)
					dist.PB( sqr(x[i] - x[j]) + sqr(y[i]-y[j]) );
			}
			sort(ALL(dist));
			if (dist[0] != dist[1]) square = false;
			if (2*dist[0] != dist[2]) square = false;
		}
		return (square) ? "It's a square" : "Not a square";
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
		cout << "Testing IsItASquare (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443333070;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		IsItASquare _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 0, 2, 2};
				int y[] = {0, 2, 0, 2};
				_expected = "It's a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 1, 5, 6};
				int y[] = {1, 6, 0, 5};
				_expected = "It's a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 0, 7, 7};
				int y[] = {0, 3, 0, 3};
				_expected = "Not a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 5000, 5000, 10000};
				int y[] = {5000, 0, 10000, 5000};
				_expected = "It's a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {1, 2, 3, 4};
				int y[] = {4, 3, 2, 1};
				_expected = "Not a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {0, 5, 3, 8};
				int y[] = {0, 0, 4, 4};
				_expected = "Not a square";
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.isSquare(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
