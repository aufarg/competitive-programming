#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int a[MAXN+5], vis[MAXN+5];

int main()
{
    int n;
    scanf("%d", &n);
    int mn, mx, fb, sb, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n == 2) {
        if (a[0] == a[1]) goto possible;
        else goto impossible;
    }
    sort(a,a+n);
    mn = a[0], mx = a[n-1];
    if (mx > 2*mn) goto impossible;
    if (mx < 2*mn-1) goto impossible;
    if (a[n-1] != a[n-2]) goto impossible;

    vis[0] = 1; vis[n-2] = 1; vis[n-1] = 1;
    fb = mn, sb = mx-mn;
    c = 1;
    for (int i = 1; c < sb && i < n-2; ++i) {
        if (vis[i]) continue;
        if (a[i] == fb+c) {
            vis[i] = 1;
            ++c;
        }
    }
    if (c != sb) goto impossible;
    c = 1;
    for (int i = 1; c < fb && i < n-2; ++i) {
        if (vis[i]) continue;
        if (a[i] == sb+c) {
            vis[i] = 1;
            ++c;
        }
    }
    if (c != fb) goto impossible;
    for (int i = 1; i < n-2; ++i) {
        if (vis[i]) continue;
        if (a[i] < fb+1) goto impossible;
        vis[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) goto impossible;
    }

possible:
    puts("Possible");
    return 0;

impossible:
    puts("Impossible");
    return 0;
}
