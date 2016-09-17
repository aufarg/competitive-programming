#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000LL

long long f(long long b, long long n)
{
    if (b > n) return n;
    else return f(b, n/b) + n % b;
}

int main()
{
    long long n, s;
    scanf("%lld%lld", &n, &s);
    if (n < s) {
        puts("-1");
        return 0;
    }
    if (n == s) {
        printf("%lld\n", n+1);
        return 0;
    }
    for (long long i = 2; i*i <= n; ++i) {
        if (f(i,n) == s) {
            printf("%lld\n", i);
            return 0;
        }
    }
    long long ans = INF;
    for (long long i = 1; i*i <= n; ++i) {
        long long l = n/(i+1)+1, r = n/i;
        while (l < r) {
            long long m = (l+r)/2;
            if (f(m,n) == s) {
                l = r = m;
            }
            else if (f(m,n) > s) {
                l = m+1;
            }
            else if (f(m,n) < s) {
                r = m-1;
            }
        }
        for (; f(l,n) < s && l >= n/(i+1)+1; --l);
        for (; f(l,n) > s && l <= n/i; ++l);
        if (f(l, n) == s) {
            ans = min(ans, l);
        }
    }
    if (ans == INF) {
        puts("-1");
    }
    else {
        printf("%lld\n", ans);
    }
    return 0;
}
