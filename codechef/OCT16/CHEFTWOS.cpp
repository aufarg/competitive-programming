#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MOD 1000000007LL

bool st[MAXN+5];

bool ok(string s)
{
    int n = s.size();
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == '2') {
            if (i+2 >= n-1) return false;
            if (s[i+1] != '2' || s[i+2] != '1') return false;
            i += 2;
        }
    }
    return true;
}

long long powmod(int pow)
{
    if (pow == 1) return 2;
    long long ret = powmod(pow/2);
    if (pow%2) return (((ret*ret)%MOD)*2)%MOD;
    else return (ret*ret)%MOD;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int cmp = 1, last = -100;
        fill(st, st+n, false);
        for (int i = 0; i < n; ++i)
            if (b[i] == '2') swap(a[i], b[i]);
        int la = -5, lb = -5;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] == '2' && la+2 < i) {
                if (i+2 >= n) goto nol;
                if (a[i+1] != '2') swap(a[i+1], b[i+1]);
                if (a[i+2] != '1') swap(a[i+2], b[i+2]);
                la = i;
            }
            if (b[i] == '2' && lb+2 < i) {
                if (i+2 >= n) goto nol;
                if (b[i+1] != '2') swap(a[i+1], b[i+1]);
                if (b[i+2] != '1') swap(a[i+2], b[i+2]);
                lb = i;
            }
        }
        if (!ok(a) || !ok(b)) goto nol;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] == '2') {
                st[i] = true;
                i += 2;
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (b[i] == '2') {
                st[i] = true;
                i += 2;
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (a[i] == b[i]) ++cmp;
            else {
                if (last+2 < i) ++cmp;
            }
            if (st[i]) last = i;
        }
        printf("%lld\n", powmod(cmp));

        continue;
nol:
        puts("0");
    }
    return 0;
}
