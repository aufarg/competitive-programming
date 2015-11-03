/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define PB push_back

typedef long long ll;

#define SZ(a) ((int)(a).size())
#define EXIST(a,s) ((s).find(a) != (s).end())

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "AnArray.cpp"
#include <string>
#include <vector>

#define MAXN 2000

map<int,int> memo[MAXN][4];

class AnArray {
	public:
	int n;
	vector<int> A;
	int gcd(ll a, ll b) { return (b) ? gcd(b, a % b) : a; }
	int dp(int n, int need, int d) {
		if (need == 0) return (d == 1) ? 1 : 0;
		if (n >= this->n) return 0;
		if (EXIST(d, memo[n][need])) return memo[n][need][d];
		int ret = dp(n+1, need, d) + dp(n+1, need-1, d/gcd(d, A[n]));
		return memo[n][need][d] = ret;
	}
	int solveProblem(vector <int> A, int K) {
		this->n = SZ(A);
		this->A = A;
		return dp(0, 3, K);
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
		cout << "Testing AnArray (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443333703;
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
		AnArray _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {31, 1, 3, 7, 2, 5};
				int K = 30;
				_expected = 1;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 1:
			{
				int A[] = {4, 5, 2, 25};
				int K = 100;
				_expected = 2;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 2:
			{
				int A[] = {100000000, 100000000, 100000000};
				int K = 1000000;
				_expected = 1;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 3:
			{
				int A[] = {269, 154, 94, 221, 171, 154, 50, 210, 258, 358, 121, 159, 8, 47, 290, 125, 291, 293, 338, 248, 295, 160, 268, 227, 99, 4, 273};
				int K = 360;
				_expected = 114;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 4:
			{
				int A[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int K = 1;
				_expected = 220;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int A[] = ;
				int K = ;
				_expected = ;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int K = ;
				_expected = ;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int K = ;
				_expected = ;
				_received = _obj.solveProblem(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
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
