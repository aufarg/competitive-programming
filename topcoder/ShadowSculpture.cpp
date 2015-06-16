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
#line 68 "ShadowSculpture.cpp"
#include <string>
#include <vector>
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 }; 
int vis[15][15][15];

class ShadowSculpture {
    public:
        int n;
        int DFS(int x, int y, int z) {
            if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n) return 0;
            if (vis[x][y][z]) return 0;
            vis[x][y][z] = 1;
            for (int i = 0; i < 6; ++i) {
                DFS(x+dx[i], y+dy[i], z+dz[i]);
            }
            return 0;
        }
        string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
            n = SZ(XY);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (XY[i][j] == 'N') {
                        for (int k = 0; k < n; ++k) {
                            vis[i][j][k] = 1;
                        }
                    }
                    else if (XY[i][j] == 'Y') {
                        bool can = false;
                        for (int k = 0; k < n; ++k) {
                            if (vis[i][j][k] == 0) 
                                can = true;
                        }
                        if (!can) return "Impossible";
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (YZ[i][j] == 'N') {
                        for (int k = 0; k < n; ++k) {
                            vis[j][k][i] = 1;
                        }
                    }
                    else if (YZ[i][j] == 'Y') {
                        bool can = false;
                        for (int k = 0; k < n; ++k) {
                            if (vis[j][k][i] == 0) 
                                can = true;
                        }
                        if (!can) return "Impossible";
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (ZX[i][j] == 'N') {
                        for (int k = 0; k < n; ++k) {
                            vis[k][i][j] = 1;
                        }
                    }
                    else if (ZX[i][j] == 'Y') {
                        bool can = false;
                        for (int k = 0; k < n; ++k) {
                            if (vis[k][i][j] == 0) 
                                can = true;
                        }
                        if (!can) return "Impossible";
                    }

                }
            }
            int count = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (!vis[i][j][k]) {
                            cout << i << j << k << endl;                    
                            ++count;
                            DFS(i,j,k);
                        }
                    }
                }
            }
            if (count <= 1) return "Possible";
            else return "Impossible";
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
        cout << "Testing ShadowSculpture (300.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1429690535;
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
        ShadowSculpture _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
                {
                    string XY[] = {"YN","NN"};
                    string YZ[] = {"YN","NN"};
                    string ZX[] = {"YN","NN"};
                    _expected = "Possible";
                    _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                }
            case 1:
                {
                    string XY[] = {"YN","NY"};
                    string YZ[] = {"YN","NY"};
                    string ZX[] = {"YN","NY"};
                    _expected = "Impossible";
                    _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                }
            case 2:
                {
                    string XY[] = {"YYY","YNY","YYY"};
                    string YZ[] = {"YYY","YNY","YYY"};
                    string ZX[] = {"YYY","YNY","YYY"};
                    _expected = "Possible";
                    _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                }
            case 3:
                {
                    string XY[] = {"YYY","YNY","YYY"};
                    string YZ[] = {"NYY","YNY","YYY"};
                    string ZX[] = {"YYY","YNY","YYN"};
                    _expected = "Impossible";
                    _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                }
            case 4:
                {
                    string XY[] = {"N"};
                    string YZ[] = {"N"};
                    string ZX[] = {"N"};
                    _expected = "Possible";
                    _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                }
                case 5:
                  {
                  string XY[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY" };
                  string YZ[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY" };
                  string ZX[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY" };
                  _expected = "Possible";
                  _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                  }
                /*case 6:
                  {
                  string XY[] = ;
                  string YZ[] = ;
                  string ZX[] = ;
                  _expected = ;
                  _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
                  }*/
                /*case 7:
                  {
                  string XY[] = ;
                  string YZ[] = ;
                  string ZX[] = ;
                  _expected = ;
                  _received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
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
