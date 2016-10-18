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
int a[N], dp[N];
void solve()
{
    int ntc; cin >> ntc;
    while (ntc--) {
        int n; cin >> n;
        int mn = INF, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; a[i] += 5;
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        int ans = INF;
        for (int p = mn-5; p <= mn; p++) {
            fill(dp + p, dp + mx + 1, INF);
            dp[p] = 0;
            for (int i = p; i < mx; i++) {
                dp[i+1] = min(dp[i+1], dp[i]+1);
                dp[i+2] = min(dp[i+2], dp[i]+1);
                dp[i+5] = min(dp[i+5], dp[i]+1);
            }
            int sum = 0;
            for (int i = 0; i < n; i++) sum += dp[a[i]];
            ans = min(ans, sum);
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

