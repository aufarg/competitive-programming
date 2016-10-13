#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000000

int a[MAXN+5], l[MAXN+5], r[MAXN+5], idx[MAXN+5];

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        l[i] = i-1, r[i] = i+1;
        idx[a[i]] = i;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int p = idx[v[i]];
        while (a[p] >= v[i]) {
            p = l[p];
            l[idx[v[i]]] = p;
        }
        p = idx[v[i]];
        while (a[p] >= v[i]) {
            p = r[p];
            r[idx[v[i]]] = p;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (long long)(r[i]-i)*(long long)(i-l[i])*(long long)a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
