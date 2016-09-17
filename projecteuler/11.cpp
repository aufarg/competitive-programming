#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[25][25];
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            scanf("%d", &a[i][j]);

    int dr[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
    int dc[] = { 1, 0, -1, 1, 0, -1, 1, -1 };
    long long ans = 0;
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            for (int dir = 0; dir < 8; ++dir) {
                if (i+4*dr[dir] >= 0 && i+4*dr[dir] < 20 && j+4*dc[dir] >= 0 && j+4*dc[dir] < 20) {
                    long long prod = 1;
                    for (int l = 0; l < 4; ++l) {
                        prod *= a[i+l*dr[dir]][j+l*dc[dir]];
                    }
                    if (prod > ans) ans = prod;
                }
            }

    printf("%lld\n", ans);
}
