#include <bits/stdc++.h>

#define MOD 1000000007
struct matrix {
    long long m[3][3];
    matrix() {
        memset(m, 0, sizeof(m));
    }
};

matrix base;

matrix mult(matrix a, matrix b)
{
    matrix ret;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) {
                ret.m[i][j] = (ret.m[i][j] + a.m[i][k] * b.m[k][j])%MOD;
            }

    return ret;
}

matrix pow(long long b)
{
    if (b == 1) {
        matrix ret;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k) {
                    ret.m[i][j] = base.m[i][j];
                }
        return ret;
    }
    matrix ret = pow(b/2);
    if (b%2==0) {
        return mult(ret, ret);
    }
    else {
        return mult(mult(ret,ret),base);
    }
}

int main()
{
    long long N;
    scanf("%lld", &N);

    int b[3][3] = {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 1, 0, 1 }
    };
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) base.m[i][j] = b[i][j];
    matrix ret = pow(N);
    long long a[3] = { 1, 2, 3 };
    long long ans[3] = { 0, 0, 0 };
    for (int i = 0; i < 3; ++i) for (int k = 0; k < 3; ++k)
        ans[i] = (ans[i] + ret.m[i][k] * a[k])%MOD;

    printf("%lld\n", ans[0]);
    return 0;
}
