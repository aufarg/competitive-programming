#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,t,a,b,m,n;
    scanf("%d%d%d%d%d%d", &s, &t, &a, &b, &m, &n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int d;
        scanf("%d", &d);
        if (s <= a+d && a+d <= t) ++ans;
    }
    printf("%d\n", ans);
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        scanf("%d", &d);
        if (s <= b+d && b+d <= t) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
