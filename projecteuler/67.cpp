#include <bits/stdc++.h>

using namespace std;

#define MAXN 120
int a[MAXN+5][MAXN+5];
int mem[MAXN+5][MAXN+5];

int dp(int r, int c)
{
    if (r == 100) return 0;
    int &ret = mem[r][c];
    if (ret >= 0) return ret;
    return ret = max(dp(r+1,c),dp(r+1,c+1))+a[r][c];
}

int main()
{
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j <= i; ++j) scanf("%d", &a[i][j]);
    }
    printf("%d\n", dp(0,0));
    return 0;
}
