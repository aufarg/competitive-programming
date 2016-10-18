#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cnt[s[0]-'A']++;
        mx = max(mx, cnt[s[i]-'A']);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int need = i*k;
        for (int c = 0; c < 26; ++c) {
            need -= min(cnt[c], i);
        }
        if (need > 0) break;
        ans = i;
    }
    printf("%d\n", ans);
}
