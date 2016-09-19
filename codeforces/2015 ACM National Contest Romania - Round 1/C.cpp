#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T GaussJordan(VVT &a, VVT &b) {
    const int n = a.size();
    const int m = b[0].size();
    VI irow(n), icol(n), ipiv(n);
    T det = 1;

    for (int i = 0; i < n; ++i) {
        int pj = -1, pk = -1;
        for (int j = 0; j < n; ++j) if (!ipiv[j])
            for (int k = 0; k < n; ++k) if (!ipiv[k])
                if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }

        ipiv[pk]++;
        swap(a[pj], a[pk]);
        swap(b[pj], b[pk]);
        if (pj != pk) det *= -1;
        irow[i] = pj;
        icol[i] = pk;
        T c = 1.0 / a[pk][pk];
        det *= a[pk][pk];
        a[pk][pk] = 1.0;

        for (int p = 0; p < n; ++p) a[pk][p] *= c;
        for (int p = 0; p < m; ++p) b[pk][p] *= c;
        for (int p = 0; p < n; ++p) if (p != pk) {
            c = a[p][pk];
            a[p][pk] = 0;
            for (int q = 0; q < n; ++q) a[p][q] -= a[pk][q] * c;
            for (int q = 0; q < m; ++q) b[p][q] -= b[pk][q] * c;
        }
    }

    for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
        for (int k = 0; k < n; ++k) swap(a[k][irow[p]], a[k][icol[p]]);
    }
    return det;
}

double a[MAXN+5][MAXN+5], b[MAXN+5][MAXN+5];

int main()
{
    freopen("bujor.in", "r", stdin);
    freopen("bujor.out", "w", stdout);
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        VVT a(n), b(n);
        for (int i = 0; i < n; ++i) {
            VT v(n), u(n);
            for (int j = 0; j < n; ++j) {
                T x;
                scanf("%lf", &x);
                v[j] = x;
            }
            a[i] = v;
            b[i] = u;;
        }

        double det = GaussJordan(a, b);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%.10lf ", a[i][j]);
            puts("");
        }
    }
    return 0;
}
