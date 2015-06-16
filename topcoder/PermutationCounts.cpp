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
#line 68 "PermutationCounts.cpp"
#include <string>
#include <vector>
class PermutationCounts {
	public:
	int countPermutations(int N, vector <int> pos) {
		
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
		cout << "Testing PermutationCounts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1429689558;
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
		PermutationCounts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int pos[] = {3};
				_expected = 9;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 13;
				int pos[] = {12,11,10,9,8,7,6,5,4,3,2,1};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 13;
				int pos[] = {};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int pos[] = {2,4,5};
				_expected = 1421;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 80;
				int pos[] = {31,41,59,26,53,58,9,79,32,3,8,46};
				_expected = 82650786;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 875;
				int pos[] = {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
				            872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
				            237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
				            212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
				            514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
				            677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
				            309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
				            865,407,121,477,567,790,127,593,57,674,114,239,599,552,738};
				_expected = 169176190;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int pos[] = ;
				_expected = ;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int pos[] = ;
				_expected = ;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int pos[] = ;
				_expected = ;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
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
