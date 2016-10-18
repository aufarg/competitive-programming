// template {{{
#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define sz(c) (static_cast<int>(c.size()))
#define endl "\n"

using ld = long double;
using ll = long long;

template <typename T, typename Z> inline T power(T base, Z exponent)
{
    T ret = 1;
    for (; exponent > 0; exponent >>= 1, base *= base)
        if (exponent & 1) ret *= base;
    return ret;
}
template <typename Z> Z gcd(const Z& a, const Z& b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename Z> Z extended_gcd(const Z& a, const Z& b, Z& x, Z& y)
{
    if (b == 0) return x = 1, y = 0, a;
    Z gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
template <typename... T>
void debug(T&&... args)
{
    ((cerr << args << " "), ..., (cerr << endl));
}
#define vardump(...) #__VA_ARGS__":", (__VA_ARGS__)

// }}}

const ll INFL = numeric_limits<ll>::max() / 2;
const ll INF = numeric_limits<int>::max() / 2;
const ll MOD = 1e9+7;

const int N = 1e5 + 5;
const int V = 1e4 + 5;
const int uN = 1e3 + 5;
int a[N], cnt[V];
bool p[V];
ll dp[uN][V];

void solve()
{
    for (int i = 2; i * i < V; i++) {
        if (!p[i]) {
            int t = i * i;
            while (t < V) {
                p[t] = true;
                t += i;
            }
        }
    }
    int ntc; cin >> ntc;
    while (ntc--) {
        int n; cin >> n;
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a, a+n);
        n = static_cast<int>(unique(a, a+n) - a);
        for (int i = 0; i < n; i++) {
            ll e = (cnt[a[i]]>>1) + 1, o = (cnt[a[i]]+1) >> 1;
            for (int j = 0; j < V; j++) {
                if (!dp[i][j]) continue;
                if ((j^a[i]) >= V) continue;
                dp[i+1][j^a[i]] += (o * dp[i][j]) % MOD;
                dp[i+1][j] += (e * dp[i][j]) % MOD;
                /* debug(i, j, a[i], dp[i][j]); */
            }
        }
        ll ans = 0;
        for (int i = 2; i < V; i++) {
            if (!p[i]) ans = (ans + dp[n][i]) % MOD;
        }
        cout << ans << endl;
    }
}

// main {{{
int main()
{
    cin.sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}
// }}}

