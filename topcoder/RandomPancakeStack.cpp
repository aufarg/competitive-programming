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
#line 68 "RandomPancakeStack.cpp"
#include <string>
#include <vector>
class RandomPancakeStack {
    public:
        int n;
        vector<int> hehe;
        int vis[300][300];
        double memo[300][300];
        double take(int n, int ch) {
            if (n == 0) return 0;
            if (vis[n][ch]) return memo[n][ch];
            double ret = 0;
            for (int i = 0; i < n; ++i) {
                if (ch-1 > 0) {
                ret += ( take(i, ch-1) + hehe[i] ) / ch;
                }
                else {
                    ret += hehe[i] / ch;
                }
            }
            vis[n][ch] = 1; memo[n][ch] = ret;
            return ret; 
        }
        double expectedDeliciousness(vector <int> d) {
            n = SZ(d);
            hehe = d;
            return take(n, n);
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
		cout << "Testing RandomPancakeStack (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1429687403;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomPancakeStack _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {1,1,1};
				_expected = 1.6666666666666667;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {3,6,10,9,2};
				_expected = 9.891666666666667;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {10,9,8,7,6,5,4,3,2,1};
				_expected = 10.999999724426809;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 7.901100088183421;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1};
				_expected = 19.368705050402465;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 5:
			{
				int d[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 1.718281828459045;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 6:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
