#include <bits/stdc++.h>

using namespace std;

#define MAXN 50
#define EPS 1e-9

int n;
double w, h;
double x[MAXN+5], y[MAXN+5], rad[MAXN+5];

double sqdist(double x1, double y1, double x2, double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int check(double xx, double yy, double r)
{
    if (xx < r || yy < r || xx+r > w || yy+r > h) goto no;
    for (int i = 0; i < n; ++i) {
        double R = rad[i]+r;
        if (sqdist(x[i], y[i], xx, yy) < R*R) goto no;
    }
    return 1;
no:
    return 0;
}

int solvable(double r)
{
    if (check(r, r, r) || check(w-r, r, r) || check(r, h-r, r) || check(w-r, h-r, r)) goto ok;

    for (int i = 0; i < n; ++i) {
        double R = rad[i]+r;
        if (x[i] < r+R) {
            double xl = r-x[i];
            double s = sqrt(R-xl)*sqrt(R+xl);
            if (check(r,y[i]+s, r) || check(r,y[i]-s,r)) goto ok;
        }
        else if (check(r,y[i], r)) goto ok;

        if (w-x[i] < r+R) {
            double xl = w-x[i]-r;
            double s = sqrt(R-xl)*sqrt(R+xl);
            if (check(w-r,y[i]+s, r) || check(w-r,y[i]-s,r)) goto ok;
        }
        else if (check(w-r,y[i],r)) goto ok;
        if (y[i] < r+R) {
            double yl = r-y[i];
            double s = sqrt(R-yl)*sqrt(R+yl);
            if (check(x[i]+s, r, r) || check(x[i]-s, r, r)) goto ok;
        }
        else if (check(x[i], r, r)) goto ok;
        if (h-y[i] < r+R) {
            double yl = h-y[i]-r;
            double s = sqrt(R-yl)*sqrt(R+yl);
            if (check(x[i]+s, h-r, r) || check(x[i]-s, h-r, r)) goto ok;
        }
        else if (check(x[i], h-r, r)) goto ok;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double R = rad[i]+rad[j]+2*r;
            if (sqdist(x[i],y[i], x[j],y[j]) > R*R) {
                double xx = x[i]+(x[j]-x[i])/R*(rad[i]+r);
                double yy = y[i]+(y[j]-y[i])/R*(rad[i]+r);
                if (check(xx, yy, r)) goto ok;
            }
            else {
                double xa = x[j]-x[i];
                double ya = y[j]-y[i];
                double ra = rad[j]+r;
                double rb = rad[i]+r;
                double R = (xa*xa+ya*ya+rb*rb-ra*ra);
                if (ya != 0.0) {
                    double a = 1.0+(xa*xa)/(ya*ya);
                    double b = -R/(ya*ya)*xa;
                    double c = (R/(4.0*ya*ya)*R-rb*rb);
                    double s = sqrt(b*b-4*a*c);
                    double x1 = (-b+s)/(2*a);
                    double s1 = sqrt(rb*rb-x1*x1);
                    double x2 = (-b-s)/(2*a);
                    double s2 = sqrt(rb*rb-x2*x2);
                    if (check(x[i]+x1, y[i]+s1, r) || check(x[i]+x2, y[i]+s2, r) ||
                            check(x[i]+x1, y[i]-s1, r) || check(x[i]+x2, y[i]-s2, r)) goto ok;
                }
                else {
                    double xd = R/(2.0*xa);
                    double s = sqrt(rb-xd)*sqrt(rb+xd);
                    if (check(x[i]+xd, y[i]+s, r) || check(x[i]+xd, y[i]-s, r)) goto ok;
                }
            }
        }
    }
    return 0;
ok:
    return 1;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%lf%lf%d", &w, &h, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf", &x[i], &y[i], &rad[i]);
        }

        double l = 0, r = min(w,h);
        while (l + EPS < r) {
            double mid = (l+r)/2.0;
            if (solvable(mid)) l = mid;
            else r = mid;
        }
        printf("%.12lf\n", l);
    }
    return 0;
}
