#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000LL

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        long long lo = 0, hi = INF;
        for (int i = 0; i < n; ++i) {
            int a; char c;
            scanf("%d %c", &a, &c);
            if (c == '-') {
                hi = min(hi, lo+a+25);
            }
            else lo += a+25;
        }
        cout << hi-lo << endl;
    }
    return 0;
}
