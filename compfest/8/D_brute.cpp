#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000000
int ans[10];
int main()
{
    for (int i = 1; i < MAXN; ++i) {
        int tmp = i;
        int len = 0;

        int rev = 0;
        while (tmp) {
            rev = rev * 10 + (tmp%10);
            tmp /= 10;
        }
        if (rev != i) continue;

        tmp = i;
        while (tmp) {
            tmp /= 10;
            ++len;
        }

        tmp = i;
        int fct = sqrt(i);
        for (int j = 1; j <= fct; ++j) {
            if (i % j == 0) {
                ans[len]++;
            }
        }
    }
    for (int i = 1; i <= 9; ++i) {
        printf("%d %d\n", i, ans[i]);
    }
}
