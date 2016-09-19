#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int c[MAXN+5], v[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
            vector<int> pts(6);
            for (int j = 0; j < c[i]; ++j) {
                int x;
                scanf("%d", &x);
                pts[--x]++;
            }
            sort(pts.begin(), pts.end());
            int l = 0;
            v[i] = c[i];
            for (int j = 0; j < 3; ++j) {
                int c;
                switch (j) {
                    case 0: c = 4; break;
                    case 1: c = 2; break;
                    case 2: c = 1; break;
                }
                v[i] += c*(pts[j]-l);
                l = pts[j];
            }
        }

        int winner = -1;
        int pts = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > pts) {
                pts = v[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] == pts) {
                if (winner == -1) winner = i;
                else goto tie;
            }
        }
        if (winner) printf("%d\n", winner+1);
        else puts("chef");
        continue;
tie:
        puts("tie");
    }
    return 0;
}
