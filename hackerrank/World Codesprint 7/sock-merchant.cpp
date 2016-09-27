#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) ans += cnt[i] / 2;
    printf("%d\n", ans);
    return 0;
}
