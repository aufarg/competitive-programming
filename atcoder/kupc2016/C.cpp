#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        if (n&1) printf("%d\n", (n-1)*127+d);
        else printf("%d\n", (n-1)*127+(d^127));
    }
}
