#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        long long s, v;
        scanf("%lld%lld", &s, &v);
        printf("%.9lf\n", (double)(2*s)/(3*v));
    }
    return 0;
}
