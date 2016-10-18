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
ll mem[N][2][2];
vector<int> edge[N];

ll dp(int v, int c, int s, int p = -1)
{
    if (p != -1 && sz(edge[v]) == 1) return s;
    ll &ret = mem[v][c][s];
    if (ret != -1) return ret;
    for (int u: edge[v]) {
        if (u == p) continue;
        ll t = (dp(u, c, 1, v) + dp(u, !c, 0, v)) % MOD;
        if (ret == -1) ret = t;
        else ret = (ret * t) % MOD;
    }
    if (!s) {
        ll t = 1;
        for (int u: edge[v]) {
            if (u == p) continue;
            t = (t * dp(u, !c, 0, v)) % MOD;
        }
        ret = ret - t;
        if (ret < 0) ret += MOD;
    }
    /* debug(v, c,  s, p, ret); */
    return ret;
}

void solve()
{
    int n; cin >> n;
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout << (dp(0, 0, 0) + dp(0, 1, 0)) % MOD << endl;
}

// main {{{
int main()
{
    cin.sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}
// }}}

