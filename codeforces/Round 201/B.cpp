#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define INF 1000000

string s, t, v;

int mem[MAXN+5][MAXN+5][MAXN+5];
int vis[MAXN+5][MAXN+5][MAXN+5];
int nxt[MAXN+5][MAXN+5][MAXN+5];
int nr[MAXN+5][MAXN+5][MAXN+5];

int kmp[MAXN+5];

int dp(int p, int q, int r)
{
    if (r+1 == v.size()) return -INF;
    if (p == s.size() || q == t.size()) return 0;
    int &ret = mem[p][q][r+1];
    if (vis[p][q][r+1]) return ret;
    vis[p][q][r+1] = 1;

    int &ptr = nxt[p][q][r+1];
    int &rptr = nr[p][q][r+1];
    int x = dp(p+1, q, r);
    int y = dp(p, q+1, r);
    ptr = (x < y);
    ret = max(x,y);
    rptr = r;
    if (s[p] == t[q]) {
        while (r > -1 && v[r+1] != s[p]) {
            r = kmp[r];
        }
        if (v[r+1] == s[p]) ++r;
        int tmp = dp(p+1, q+1, r)+1;
        if (ret < tmp) {
            rptr = r;
            ret = tmp;
            ptr = 2;
        }
    }
    return ret;
}

int main()
{
    memset(nxt, -1, sizeof(nxt));
    cin >> s >> t >> v;
    kmp[0] = -1;
    for (int i = 0; i+1 < v.size(); ++i) {
        int j = kmp[i];
        while (j > -1 && v[i+1] != v[j+1]) {
            j = kmp[j];
        }
        kmp[i+1] = j+(v[i+1] == v[j+1]);
    }

    int ret = dp(0, 0, -1);
    if (ret <= 0) {
        puts("0");
        return 0;
    }


    int p = 0, q = 0, r = 0;
    while (nxt[p][q][r] != -1) {
        switch (nxt[p][q][r]) {
            case 0:
                ++p;
                break;
            case 1:
                ++q;
                break;
            case 2:
                printf("%c", s[p]);
                r = nr[p][q][r]+1;
                ++p; ++q;
                break;
            default:
                assert(false);
        }
    }
    puts("");
    return 0;
}
