#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y, a, b;
    scanf("%lf%lf%lf%lf", &x, &y, &a, &b);
    double l = a*a+b*b;
    double k = x*a + y*b;
    double n = a*y - x*b;

    printf("%lf\n%lf\n", k/l, n/l);
    return 0;
}
