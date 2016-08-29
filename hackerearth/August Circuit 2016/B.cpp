#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    return (b) ? gcd(b, a%b) : a;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        long long a = m * (9 * n * 4 * n);
        long long b = n * 4 * (m * 9 * n + (n-m) * 8 * n);
        long long g = gcd(a,b);
        printf("%lld/%lld\n", a/g,b/g);
    }
    return 0;
}
