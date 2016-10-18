#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x < a || x >= b) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
