#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int n;
        scanf("%d", &n);
        if (n%2) puts("No");
        else puts("Yes");
    }
    return 0;
}
