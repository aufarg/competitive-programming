#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define MAXM 1000
#define MAXQ 100000

vector<int> edge[MAXQ+5];

int n, m, q;
int books[MAXN+5][MAXM+5];
int v_ans[MAXQ+5];
int t[MAXQ+5], a[MAXQ+5], b[MAXQ+5];


void dfs(int v, int last_ans)
{
    int &ans = v_ans[v];
    ans = last_ans;
    int tmp;
    switch (t[v]) {
        case 1:
            tmp = books[a[v]][b[v]];
            if (!books[a[v]][b[v]]) {
                books[a[v]][b[v]] = 1;
                ans++;
            }
            for (auto &u: edge[v]) {
                dfs(u, ans);
            }
            books[a[v]][b[v]] = tmp;
            break;
        case 2:
            tmp = books[a[v]][b[v]];
            if (books[a[v]][b[v]]) {
                books[a[v]][b[v]] = 0;
                ans--;
            }
            for (auto &u: edge[v]) {
                dfs(u, ans);
            }
            books[a[v]][b[v]] = tmp;
            break;
        case 3:
            for (int i = 1; i <= m; ++i) {
                ans += (books[a[v]][i]) ? -1 : 1;
                books[a[v]][i] = !books[a[v]][i];
            }
            for (auto &u: edge[v]) {
                dfs(u, ans);
            }
            for (int i = 1; i <= m; ++i) {
                books[a[v]][i] = !books[a[v]][i];
            }
            break;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    int par = 0;
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &t[i]);
        switch (t[i]) {
            case 1:
                scanf("%d%d", &a[i], &b[i]);
                break;
            case 2:
                scanf("%d%d", &a[i], &b[i]);
                break;
            case 3:
                scanf("%d", &a[i]);
                break;
            case 4:
                scanf("%d", &par);
                while (t[par] == 4) par = a[par];
                a[i] = par;
                break;
        }
        switch (t[i]) {
            case 1:
            case 2:
            case 3:
                edge[par].push_back(i);
                par = i;
                break;
        }
    }
    for (auto &v: edge[0]) {
        dfs(v, 0);
    }

    for (int i = 1; i <= q; ++i) {
        switch (t[i]) {
            case 1:
            case 2:
            case 3:
                printf("%d\n", v_ans[i]);
                break;
            case 4:
                printf("%d\n", v_ans[a[i]]);
                break;
        }
    }

    return 0;
}
