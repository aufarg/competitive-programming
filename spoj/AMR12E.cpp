#include<bits/stdc++.h>

using namespace std;

#define MAXN 400
#define MAXK 11
#define MOD 1000000007LL

int n, k;
int mem[MAXN+5][(1<<MAXK)+5];
bool vis[MAXN+5][(1<<MAXK)+5];

inline bool pal(int m, int l)
{
    m = m&((1<<l)-1);
    int t = m, p = 0;
    for (int i = 0; i < l; ++i) {
        p = (p<<1)+(t&1);
        t >>= 1;
    }
    return p == m;
}

long long dp(int p, int m)
{
    if ((p >= k && pal(m, k)) || (p >= k+1 && pal(m, k+1))) return 0LL;
    if (p == n) return 1LL;
    int &ret = mem[p][m];
    if (vis[p][m]) return ret;
    vis[p][m] = true;
    int mask = (1<<(k+1))-1;
    return ret = (dp(p+1, (m<<1)&mask) + dp(p+1, ((m<<1)|1)&mask)) % MOD;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d%d", &n, &k);
        memset(vis, 0, sizeof(vis));
        printf("%lld\n", dp(0, 0));
    }
    return 0;
}
