#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007LL
#define MAXN 1000000

long long a[MAXN+5], d[MAXN+5], s[MAXN+5], p[MAXN+5], r[MAXN+5];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    int tsum = 0;
    int two = 0;
    for (int i = n-1; i >= 0; --i) {
        d[i] = ((tsum+(n-i))*a[i] + s[i+1] + (r[i+1] + p[i+1])) % MOD;
        s[i] = (s[i+1] + d[i]) % MOD;
        p[i] = (p[i+1] + (two+1)*a[i]) % MOD;
        r[i] = (r[i+1] + p[i+1] + (tsum+(n-i))*a[i]) % MOD;
        tsum = ((tsum*2)+(n-i)) % MOD;
        two = (2*two+1) % MOD;
    }
    printf("%lld\n", d[0]);
}
