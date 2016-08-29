#include<bits/stdc++.h>

using namespace std;

#define MAXN 50
#define MAXV 2500

long long dp[MAXN+5][MAXN+5][MAXV+5];
int x[MAXN+5];
int n, a;

long long ways(int p, int c, int s)
{
    if (p == n) {
        return (c > 0 && c*a == s);
    }
    long long &ret = dp[p][c][s];
    if (ret >= 0) return ret;
    return ret = ways(p+1, c+1, s+x[p]) + ways(p+1, c, s);
}

int main()
{
    scanf("%d%d", &n, &a);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n",ways(0, 0, 0));
    return 0;
}
