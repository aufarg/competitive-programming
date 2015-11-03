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

// BEGIN CUT HERE

// END CUT HERE
#line 68 "CatsOnTheCircle.cpp"
#include <string>
#include <vector>
class CatsOnTheCircle {
	public:
	double getProb(int N, int K, int p) {
		
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
		cout << "Testing CatsOnTheCircle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443615086;
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
		CatsOnTheCircle _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 1;
				int p = 300000000;
				_expected = 0.6999999999999985;
				_received = _obj.getProb(N, K, p); break;
			}
			case 1:
			{
				int N = 6;
				int K = 2;
				int p = 500000000;
				_expected = 0.2;
				_received = _obj.getProb(N, K, p); break;
			}
			case 2:
			{
				int N = 6;
				int K = 5;
				int p = 500000000;
				_expected = 0.2;
				_received = _obj.getProb(N, K, p); break;
			}
			case 3:
			{
				int N = 10;
				int K = 2;
				int p = 666666666;
				_expected = 0.00391389439551009;
				_received = _obj.getProb(N, K, p); break;
			}
			case 4:
			{
				int N = 999999999;
				int K = 999999996;
				int p = 777777777;
				_expected = 0.05830903870125612;
				_received = _obj.getProb(N, K, p); break;
			}
			case 5:
			{
				int N = 1000000000;
				int K = 4;
				int p = 300000000;
				_expected = 0.044981259448371;
				_received = _obj.getProb(N, K, p); break;
			}
			case 6:
			{
				int N = 534428790;
				int K = 459947197;
				int p = 500000000;
				_expected = 1.871156682766205E-9;
				_received = _obj.getProb(N, K, p); break;
			}
			/*case 7:
			{
				int N = ;
				int K = ;
				int p = ;
				_expected = ;
				_received = _obj.getProb(N, K, p); break;
			}*/
			/*case 8:
			{
				int N = ;
				int K = ;
				int p = ;
				_expected = ;
				_received = _obj.getProb(N, K, p); break;
			}*/
			/*case 9:
			{
				int N = ;
				int K = ;
				int p = ;
				_expected = ;
				_received = _obj.getProb(N, K, p); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
