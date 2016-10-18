#include <bits/stdc++.h>

using namespace std;

long long cyclefind(long long a, long long b)
{
    long long r = a % b;
    long long p = (r*10)%b, q = (r*100)%b;
    int kx = 0;
    while (p != q) {
        ++kx;
        p = (p*10) % b;
        q = (q*100) % b;
    }
    if (p == 0) return 0;
    q = r;
    int mu = 0;
    while (p != q) {
        ++mu;
        p = (p*10) % b;
        q = (q*10) % b;
    }
    q = (p*10) % b;
    int lambda = 1;
    while (p != q) {
        q = (q*10) % b;
        ++lambda;
    }
    return lambda;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %lld\n", itc, cyclefind(a, b));
    }
    return 0;
}
