#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, k, n;
    scanf("%d%d%d", &d, &k, &n);
    int p;
    if (k%2) p = (k-1+n)%d;
    else p = ((k-1-n)%d+d)%d;
    int l = (p+1)%d;
    int r = (p+d-1)%d;
    if (k % 2) printf("%d %d\n", (l+n)%d+1, (r+n)%d+1);
    else printf("%d %d\n", ((l-n)%d+d)%d+1, ((r-n)%d+d)%d+1);
    return 0;
}
