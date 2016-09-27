#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

#define MAXN 16

int v[MAXN+5][MAXN+5], a[MAXN+5][MAXN+5];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m), n != 0 || m != 0) {
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                v[i][j] = (s[j] == 'X');
            }
        }
        int ans = INF;
        for (int k = 0; k < (1<<m); ++k) {
            int flip = 0;
            for (int i = 0; i <= n; ++i) for (int j = 0; j < m; ++j) a[i][j] = v[i][j];
            for (int i = 0; i < m; ++i) {
                if (k&(1<<i)) a[0][i] = 1;
                else a[0][i] = 0;
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i-1][j]) {
                        a[i][j] = !a[i][j];
                        if (j) a[i][j-1] = !a[i][j-1];
                        if (j+1 < m) a[i][j+1] = !a[i][j+1];
                        a[i+1][j] = !a[i+1][j];
                        ++flip;
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < m; ++i) if (a[n][i]) ok = 0;
            if (ok) ans = min(ans, flip);
        }
        if (ans == INF) puts("Damaged billboard.");
        else printf("You have to tap %d tiles.\n", ans);
    }
    return 0;
}
