#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long la, lb;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if (!i) { la = a; lb = b; }
        else {
            long long d = max((la+a-1)/a, (lb+b-1)/b);
            la = d * a;
            lb = d * b;
        }
        /* printf("%lld %lld\n", la, lb); */
    }
    /* printf("%lld %lld\n", la, lb); */
    printf("%lld\n", la+lb);
    return 0;
}
