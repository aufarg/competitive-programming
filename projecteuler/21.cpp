#include <bits/stdc++.h>

using namespace std;

int vis[10005];

int f(int x)
{
    int ret = 0;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            if (i*i == x) ret += i;
            else ret += x/i+i;
        }
    }
    return ret+1;
}

int main()
{
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        int a = f(i);
        int b = f(a);
        if (a != b && b == i) {
            if (a < 10000) vis[a] = 1;
            if (b < 10000) vis[b] = 1;
        }
    }
    for (int i = 0; i < 10000; ++i) {
        if (vis[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
