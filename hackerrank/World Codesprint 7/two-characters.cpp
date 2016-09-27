#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
char s[MAXN+5];
vector<int> idx[30];
int main()
{
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        idx[s[i]-'a'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = i+1; j < 26; ++j) {
            if (i == j) continue;
            int p = 0, q = 0;
            bool ok = true;
            vector<int> pos;
            for (int k = 0; k < idx[i].size(); ++k) pos.push_back(idx[i][k]);
            for (int k = 0; k < idx[j].size(); ++k) pos.push_back(idx[j][k]);
            sort(pos.begin(), pos.end());
            int l = pos.size();
            for (int k = 0; k+1 < l; ++k) {
                if (s[pos[k]] == s[pos[k+1]]) ok = false;
            }
            if (ok) ans = max(ans, l);
        }
    }
    if (ans > 1) printf("%d\n", ans);
    else puts("0");
    return 0;
}
