#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        int h = -1;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (a < 2) continue;
            int prime = 1;
            for (int  j = 2; j*j <= a; ++j)
                if (a%j==0) {
                    prime = 0;
                    break;
                }
            if (prime) {
                h = max(h, a*a);
            }
        }
        printf("%d\n", h);
    }
}
