#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        switch (t) {
            case 1:
                int i, j;
                scanf("%d%d", &i, &j);
                break;
            case 2:
                int i, j;
                scanf("%d%d", &i, &j);
                break;
            case 3:
                int i;
                scanf("%d", &i);
                break;
            case 4:
                int k;
                scanf("%d", &k);
                break;
        }
    }
    return 0;
}
