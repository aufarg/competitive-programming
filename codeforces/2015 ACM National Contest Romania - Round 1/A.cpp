#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define MOD 1000000007

int n;
int a[MAXN+5];
int vis[MAXN+5][2];
long long mem[MAXN+5][2];

long long dp(int p, int s)
{
    if (p >= n) return (s == 0);
    long long &ret = mem[p][s];
    if (vis[p][s]) return ret;
    vis[p][s] = 1;
    ret = (dp(p+1, s) + dp(p+1, (s+a[p]%2)%2)) % MOD;
    return mem[p][s] = ret;
}

int main()
{
    freopen("azerah.in", "r", stdin);
    freopen("azerah.out", "w", stdout);

    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + dp(i+1, a[i]%2)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
