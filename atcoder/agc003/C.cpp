#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int a[MAXN+5];
vector<int> v;
map<int,int> id;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    int order = 0;
    sort(v.begin(), v.end());
    for (auto k: v) {
        id[k] = order;
        ++order;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (id[a[i]] % 2 != i % 2) {
            ++ans;
        }
    }
    printf("%d\n", ans/2);
    return 0;
}
