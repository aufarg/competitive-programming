#include <bits/stdc++.h>

using namespace std;

pair<long long,pair<long long,long long>> ext_gcd(long long a, long long b)
{
    if (b == 0) return make_pair(a, make_pair(1, 0));
    long long q = a/b;
    pair<long long, pair<long long,long long>> pr = ext_gcd(b, a-q*b);
    long long x = pr.second.first;
    long long y = pr.second.second;
    return make_pair(pr.first, make_pair(y, x-q*y));
}

int main()
{
    long long a1,b1,a2,b2,L,R;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    if (a1 < a2) {
        swap(a1,a2);
        swap(b1,b2);
    }
    pair<long long, pair<long long,long long>> ext = ext_gcd(a1, a2);
    long long g = ext.first;
    long long l = ext.second.first;
    long long r = -ext.second.second;
    if ((b2-b1) % g == 0) {
        long long k = (b2-b1) / g;
        l *= k;
        r *= k;
        long long c = min(l/(a2/g),r/(a1/g));
        l -= a2/g*c;
        r -= a1/g*c;
        while (l < 0 || r < 0) {
            l += a2/g;
            r += a1/g;
        }
        while (l-a2/g >= 0 && r-a1/g >= 0) {
            l -= a2/g;
            r -= a1/g;
        }

        long long v = a1*l+b1;
        L -= v;
        R -= v;
        long long lcm = a1/g*a2;
        if (R < 0) {
            puts("0");
        }
        else if (L <= 0) {
            cout << R/lcm + 1 << endl;
        }
        else {
            cout << R/lcm-(max(0LL, L-1)/lcm) << endl;
        }
    }
    else {
        puts("0");
    }
}
