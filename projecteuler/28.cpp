#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans = 1;
    long long cur = 1;
    const long long N = 1001;
    for (long long i = 1; i <= N/2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cur += i*2;
            ans += cur;
        }
    }
    printf("%lld\n", ans);
}
