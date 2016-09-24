#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = n;
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]]++;
    }
    ans = min(ans, cnt['h']/2);
    ans = min(ans, cnt['a']/2);
    ans = min(ans, cnt['c']);
    ans = min(ans, cnt['k']);
    ans = min(ans, cnt['e']/2);
    ans = min(ans, cnt['r']/2);
    ans = min(ans, cnt['t']);
    printf("%d\n", ans);
}
