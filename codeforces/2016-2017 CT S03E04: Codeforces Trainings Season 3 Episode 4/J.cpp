#include <bits/stdc++.h>

using namespace std;

#define OFFSET (1<<10)
inline bool ok(vector<int> &v)
{
    for (int i = 0; i+1 < v.size(); ++i) {
        if (v[i] > v[i+1]) return false;
    }
    return true;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        int ans = 5;
        scanf("%d", &n);
        map<vector<int>, int> vis;
        queue<vector<int> > Q;
        vector<int> s;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            s.push_back(a);
        }
        Q.push(s);
        vis[s] = 0;
        while (!Q.empty()) {
            vector<int> &v = Q.front();
            int d = vis[v];
            for (int i = 0; i <= n; ++i) {
                for (int k = i+1; k <= n; ++k) {
                    for (int j = i+1; j < k; ++j) {
                        vector<int> ns;
                        for (int l = 0; l < i; ++l) ns.push_back(v[l]);
                        for (int l = j; l < k; ++l) ns.push_back(v[l]);
                        for (int l = i; l < j; ++l) ns.push_back(v[l]);
                        for (int l = k; l < n; ++l) ns.push_back(v[l]);
                        if (!vis.count(ns)) {
                            vis[ns] = d+1;
                            if (d < 1) Q.push(ns);
                        }
                    }
                }
            }
            Q.pop();
        }
        while (!Q.empty()) Q.pop();
        s.clear();
        for (int i = 1; i <= n; ++i) s.push_back(i);
        if (vis.find(s) != vis.end()) {
            ans = vis[s];
            goto end;
        }
        Q.push(s);
        vis[s] = OFFSET;
        while (!Q.empty()) {
            vector<int> &v = Q.front();
            int d = vis[v]-OFFSET;
            for (int i = 0; i <= n; ++i) {
                for (int k = i+1; k <= n; ++k) {
                    for (int j = i+1; j < k; ++j) {
                        vector<int> ns;
                        for (int l = 0; l < i; ++l) ns.push_back(v[l]);
                        for (int l = j; l < k; ++l) ns.push_back(v[l]);
                        for (int l = i; l < j; ++l) ns.push_back(v[l]);
                        for (int l = k; l < n; ++l) ns.push_back(v[l]);
                        if (vis.count(ns)) {
                            if (vis[ns] < OFFSET) {
                                ans = vis[ns]+d+1;
                                goto end;
                            }
                        }
                        else if (d < 1) {
                            vis[ns] = (d+1)+OFFSET;
                            Q.push(ns);
                        }
                    }
                }
            }
            Q.pop();
        }
end:
        if (ans > 4) puts("5 or more");
        else printf("%d\n", ans);
    }
}
