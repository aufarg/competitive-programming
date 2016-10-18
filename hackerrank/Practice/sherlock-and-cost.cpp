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
int b[N], dp[N][2];
void solve()
{
    int ntc; cin >> ntc;
    while (ntc--) {
        int n; cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(b[i-1]-1));
            dp[i][1] = max(dp[i-1][0] + abs(b[i]-1), dp[i-1][1] + abs(b[i]-b[i-1]));
        }
        cout << max(dp[n-1][0], dp[n-1][1]) << endl;
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

