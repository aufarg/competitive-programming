#include <bits/stdc++.h>

using namespace std;

#define MAXT 10000003

int logt[MAXT/100+5];

int main()
{
    freopen("pocnitoare.in", "r", stdin);
    freopen("pocnitoare.out", "w", stdout);
    long long n, a, b, x, q, cq;
    cin >> n >> a >> b >> x >> q >> cq;
    logt[0] = x;
    for (int i = 1; i <= MAXT; ++i) {
        long long nx = (i*x + a) % n;
        if (i % 100 == 0) logt[i/100] = nx;
        x = nx;
    }

    for (long long iq = 1; iq <= q; ++iq) {
        long long mq = cq-1;
        long long cx = logt[mq/100];
        long long sx = (mq/100)*100+1;
        long long r = mq%100;
        for (long long i = 0; i < r; ++i ) {
            long long nx = ((sx+i)*cx+a)%n;
            cx = nx;
        }
        printf("%I64d\n", cx);
        cq = (iq*cx+b) % MAXT + 1;
    }

    return 0;
}
