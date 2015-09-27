/* DELAPAN.3gp */
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

#define SZ(a) ((int)(a).size())
inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

// BEGIN CUT HERE

// END CUT HERE
#line 68 "VerySecureEncryption.cpp"
#include <string>
#include <vector>
class VerySecureEncryption {
	public:
	string encrypt(string message, vector <int> key, int K) {
		for (int i = 0; i < K; ++i) {
			string newstring = message;
			for (int i = 0; i < SZ(key); ++i)
				newstring[key[i]] = message[i];
			message = newstring;
		}
		return message;
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
		cout << "Testing VerySecureEncryption (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443332099;
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
		VerySecureEncryption _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string message = "abc";
				int key[] = {1,2,0};
				int K = 1;
				_expected = "cab";
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}
			case 1:
			{
				string message = "abcde";
				int key[] = {4, 3, 2, 1, 0};
				int K = 1;
				_expected = "edcba";
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}
			case 2:
			{
				string message = "abcde";
				int key[] = {4, 3, 2, 1, 0};
				int K = 2;
				_expected = "abcde";
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}
			case 3:
			{
				string message = "uogcodlk";
				int key[] = {4, 3, 6, 2, 5, 1, 0, 7};
				int K = 44;
				_expected = "goodluck";
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}
			/*case 4:
			{
				string message = ;
				int key[] = ;
				int K = ;
				_expected = ;
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}*/
			/*case 5:
			{
				string message = ;
				int key[] = ;
				int K = ;
				_expected = ;
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				string message = ;
				int key[] = ;
				int K = ;
				_expected = ;
				_received = _obj.encrypt(message, vector <int>(key, key+sizeof(key)/sizeof(int)), K); break;
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
