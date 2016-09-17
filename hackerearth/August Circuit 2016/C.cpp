#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1.0L);

int main()
{
    int n;
    long double D, R;
    scanf("%d%Lf%Lf", &n, &D, &R);
    long double ans = 0.0L;
    for (int i = 0; i < n; ++i) {
        long double x, y;
        scanf("%Lf%Lf", &x, &y);
        long double sq_dist = x*x+y*y;
        long double d = sqrt(sq_dist);
        if (d <= R+D) {
            if (D <= d+R) {
                if (R <= d+D) {
                    long double rad1 = acos((R*R+d*d-D*D)/(2.0L*R*d));
                    long double area1 = R*R*rad1;

                    long double rad2 = acos((D*D+d*d-R*R)/(2.0L*D*d));
                    long double area2 = D*D*rad2;

                    long double area3 = (sqrt(-d+R+D)*sqrt(d+R-D)*sqrt(d-R+D)*sqrt(d+R+D))/2.0L;

                    ans += (area1 + area2 - area3) / (R*R*PI);
                }
                else {
                    ans += (D*D)/(R*R);
                }
            }
            else {
                ans += 1.0L;
            }
        }
    }
    printf("%.4Lf\n", ans);
}
