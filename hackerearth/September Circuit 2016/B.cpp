#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int sum[MAXN+5];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        int cnt = 0;
        while (x) { x/=2; ++cnt; }
        sum[i] = sum[i-1] + cnt;
    }
    for (int qq = 0; qq < q; ++qq) {
        int l, r;
        scanf("%d%d", &l, &r);
        if ((sum[r]-sum[l-1])%2) puts("Mishki");
        else puts("Hacker");
    }
    return 0;
}
