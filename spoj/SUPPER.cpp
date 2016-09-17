#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
struct BIT
{
    int f[MAXN+5];
    BIT()
    {
        memset(f, 0, sizeof(f));
    }

    void update(int x, int c)
    {
        for (; x <= MAXN; x+=x&(-x)) {
            f[x] = max(f[x], c);
        }
    }

    int query(int x)
    {
        int ret = 0;
        for (; x; x-=x&(-x)) {
            ret = max(f[x], ret);
        }
        return ret;
    }
};

int a[MAXN+5];
int lis[MAXN+5], lds[MAXN+5];
int ok[MAXN+5];

int main()
{
    for (int tc = 0; tc < 10; ++tc) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        BIT lisbit, ldsbit;
        memset(lis, 0, sizeof(lis));
        memset(lds, 0, sizeof(lds));
        memset(ok, 0, sizeof(ok));
        int lng = 0;
        for (int i = 0; i < n; ++i) {
            lis[i] = lisbit.query(a[i]-1)+1;
            lisbit.update(a[i], lis[i]);
            lng = max(lng, lis[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            lds[i] = ldsbit.query(n-a[i])+1;
            ldsbit.update(n-a[i]+1, lds[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (lis[i]+lds[i] == lng+1) {
                ans.push_back(a[i]);
            }
        }
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end());
        int space = 0;
        for (auto &v: ans) {
            if (space) printf(" ");
            space = 1;
            printf("%d", v);
        }
        puts("");
    }
    return 0;
}
