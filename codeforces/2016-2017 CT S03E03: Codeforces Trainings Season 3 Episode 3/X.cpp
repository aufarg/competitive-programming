#include <bits/stdc++.h>

using namespace std;

int a[15];

int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= 12; ++i) {
        scanf("%d", &a[i]);
    }
    int mx = 0, imx = -1;
    int p = -1, q = -1;
    int ans = 0;
    for (int i = 12; i; --i) {
        int cnt = m/a[i];
        if (cnt*(mx-a[i]) == ans && a[p] > a[i]) { p = i; q = imx; }
        else if (cnt*(mx-a[i]) > ans) {
            ans = cnt*(mx-a[i]);
            p = i;
            q = imx;
        }
        if (a[i] > mx) {
            mx = a[i];
            imx = i;
        }
    }
    if (ans > 0) printf("%d %d %d\n", p, q, ans);
    else puts("IMPOSSIBLE");
    return 0;
}
