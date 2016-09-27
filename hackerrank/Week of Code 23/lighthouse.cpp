#include <bits/stdc++.h>

using namespace std;

#define MAXN 50

char a[MAXN+5][MAXN+5];

inline int sqr(int a)
{
    return a*a;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j];
        }
    }
    int ans = 0;
    for (int r = 0; r <= n; ++r) {
        int can = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (min(min(i,n-i-1), min(j,n-j-1)) < r) continue;
                can = 1;
                for (int ii = 0; ii < n; ++ii) {
                    for (int jj = 0; jj < n; ++jj) {
                        if (sqr(ii-i)+sqr(jj-j) <= r*r) {
                            if (a[ii][jj] == '*') {
                                can = 0;
                                goto no;
                            }
                        }
                    }
                }
                if (can) goto check;
no:
                continue;
            }
        }
check:
        if (can) ans = r;
    }

    printf("%d\n", ans);
    return 0;
}
