#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAXV 2500

int prime[MAXV+5];
long long x[MAXN+5], y[MAXN+5];
vector<long long> primes;
map<long long,long long> gs;
set<long long> v;

int main()
{
    for (long long i = 2; i <= MAXV; ++i) {
        if (prime[i] == 0) {
            primes.push_back(i);
            int t = i*i;
            while (t <= MAXV) {
                prime[t] = 1;
                t += i;
            }
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        long long a;
        scanf("%lld", &a);

        long long tmp = a;
        long long k = 1, n = 1;
        for (auto &p: primes) {
            int cnt = 0;
            while (tmp % p == 0) {
                tmp /= p;
                ++cnt;
            }
            if (cnt % 3 == 1) {
                k *= 1LL*p*p;
                n *= 1LL*p;
            }
            if (cnt % 3 == 2) {
                k *= 1LL*p;
                n *= 1LL*p*p;
            }

        }
        n *= tmp;

        long long s = sqrt(tmp);
        while (s*s < tmp) ++s;
        while (s*s > tmp) --s;
        if (s*s == tmp) {
            k *= s;
        }
        else {
            k *= tmp*tmp;
        }

        x[i] = k; y[i] = n;
        if (n > 1) {
            gs[k]++;
        }
    }

    int ans = 0;
    int nocube = 1;
    for (int i = 0; i < n; ++i) {
        if (x[i] == 1) {
            if (nocube) {
                ++ans;
                nocube = 0;
            }
            continue;
        }
        if (v.find(x[i]) == v.end() && v.find(y[i]) == v.end()) {
            ans += max(gs[x[i]], gs[y[i]]);
            v.insert(x[i]);
            v.insert(y[i]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
