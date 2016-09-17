#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int a[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a,a+n);
        int p, q;
        p = 0; q = 1;
        int ans = n;
        while (q < n) {
            while (q < n && a[q] < 2*a[p]) ++q;
            if (q < n && a[q] >= 2*a[p]) {
                --ans;
            }
            ++p; ++q;
        }
        printf("Case %d: %d\n", itc, ans);
    }
    return 0;
}
