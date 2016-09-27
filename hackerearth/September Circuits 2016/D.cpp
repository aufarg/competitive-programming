#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        double x1, y1, x2, y2, v1, v2;
        cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
        x2 -= x1; x1 = 0.0; x2 = abs(x2);
        double l = 0.0, r = x2;
        for (int ts = 0; ts < 200; ++ts) {
            double m1 = l+(r-l)/3.0;
            double m2 = r-(r-l)/3.0;
            double d1 = dist(x1, y1, m1, 0)/v1+dist(m1, 0, x2, y2)/v2;
            double d2 = dist(x1, y1, m2, 0)/v1+dist(m2, 0, x2, y2)/v2;
            if (d1+EPS < d2) r = m2;
            else l = m1;
        }
        printf("%.5lf\n", dist(x1, y1, l, 0)/v1+dist(l, 0, x2, y2)/v2);
    }
    return 0;
}
