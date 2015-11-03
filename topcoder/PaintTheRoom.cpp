/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "PaintTheRoom.cpp"
#include <string>
#include <vector>
class PaintTheRoom {
	public:
	string canPaintEvenly(int R, int C, int K) {
		return (R % 2 == 0 || C % 2 == 0 || K == 1) ? "Paint" : "Cannot paint";
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
		cout << "Testing PaintTheRoom (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443361245;
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
		PaintTheRoom _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 1;
				int C = 1;
				int K = 1;
				_expected = "Paint";
				_received = _obj.canPaintEvenly(R, C, K); break;
			}
			case 1:
			{
				int R = 1;
				int C = 1;
				int K = 2;
				_expected = "Cannot paint";
				_received = _obj.canPaintEvenly(R, C, K); break;
			}
			case 2:
			{
				int R = 1;
				int C = 2;
				int K = 2;
				_expected = "Paint";
				_received = _obj.canPaintEvenly(R, C, K); break;
			}
			case 3:
			{
				int R = 2;
				int C = 2;
				int K = 3;
				_expected = "Paint";
				_received = _obj.canPaintEvenly(R, C, K); break;
			}
			/*case 4:
			{
				int R = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.canPaintEvenly(R, C, K); break;
			}*/
			/*case 5:
			{
				int R = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.canPaintEvenly(R, C, K); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.canPaintEvenly(R, C, K); break;
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
