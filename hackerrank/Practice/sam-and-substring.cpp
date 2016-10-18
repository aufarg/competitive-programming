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

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur = (cur * 10 + (i+1) * (s[i]-'0')) % MOD;
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
}

// main {{{
int main()
{
    cin.sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}
// }}}

