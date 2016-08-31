#include <bits/stdc++.h>

using namespace std;

int factor_size(int x) {
    int ret = 0;
    for (int i = 1; i*i <= x; ++i) {
        if (x % i == 0) {
            if (i*i == x) {
                ++ret;
            }
            else {
                ret += 2;
            }
        }
    }
    return ret;
}
int main()
{
    int ans = 1;
    while (true) {
        int f;
        if (ans % 2 == 0) {
            f = factor_size(ans/2) * factor_size(ans+1);
        }
        else {
            f = factor_size(ans) * factor_size((ans+1)/2);
        }
        if (f >= 500) {
            printf("%d\n", ans*(ans+1)/2);
            return 0;
        }
        ++ans;
    }
    return 0;
}
