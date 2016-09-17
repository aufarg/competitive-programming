#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int a[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int layer = 31;
        for (; layer >= 0; --layer) {
            int odd = 0, even = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] & (1<<layer)) ++odd;
                else ++even;
            }
            if (odd % 2 != 0) {
                int p = (odd+1)/2;
                if (p == 1 || (p%2 == 1)) {
                    for (int i = 0; i < n; ++i) {
                        if (a[i] & (1<<layer)) {
                            printf("Alice\n%d\n", a[i]);
                            goto next;
                        }
                    }
                    assert(false);
                }
                else if (even % 2 == 1) {
                    for (int i = 0; i < n; ++i) {
                        if ((a[i] & (1<<layer)) == 0) {
                            printf("Alice\n%d\n", a[i]);
                            goto next;
                        }
                    }
                    assert(false);
                }
                else {
                    puts("Bob");
                    goto next;
                }
            }
        }
        puts("Draw");
next:
        {}
    }
    return 0;
}
