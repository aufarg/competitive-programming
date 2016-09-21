#include <bits/stdc++.h>

using namespace std;

#define MAXN 1500
vector<pair<int,int>> edge[MAXN+5];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back(make_pair(b,c));
    }
    for (int i = 1; i <= n; ++i) {
    }
    return 0;
}
