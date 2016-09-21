#include <bits/stdc++.h>

using namespace std;

#define MAXN 500
set<int> home;
vector<int> pas[MAXN+5];
int ans[MAXN+5];

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    int e;
    scanf("%d", &e);
    for (int i = 0; i < e; ++i) {
        int h, p;
        scanf("%d%d", &h, &p);
        home.insert(h);
        pas[h].push_back(p);
    }
    int ok = 1;
    for (auto &h: home) {
        if (h == t) {
            ans[h] = 0;
            continue;
        }
        sort(pas[h].begin(), pas[h].end());
        reverse(pas[h].begin(), pas[h].end());
        int sum = 0;
        int need = pas[h].size();
        int cnt = 0;
        for (int i = 0; sum < need && i < pas[h].size(); ++i) {
            int v = pas[h][i];
            sum += v;
            ++cnt;
        }
        if (sum < need) ok = 0;
        ans[h] = cnt;
    }
    if (ok) {
        int space = 0;
        for (int i = 1; i <= n; ++i) {
            if (space) putchar(' ');
            space = 1;
            printf("%d", ans[i]);
        }
        puts("");
    }
    else puts("IMPOSSIBLE");
    return 0;
}
