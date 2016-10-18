#include <bits/stdc++.h>

using namespace std;

#define MAXN 18
#define INF 100000

int a[MAXN+5][MAXN+5];
int vis[MAXN+5];
int vl[(1<<MAXN)+5], vr[(1<<MAXN)+5];

void fill(int n, int t, int s, int m, int *v)
{
    if (t == 0) v[m] = max(v[m], s);
    else {
        for (int i = 0; i < n; ++i)
            if (!vis[i]) for (int j = i+1; j < n; ++j)
                if (!vis[j]) for (int k = j+1; k < n; ++k)
                    if (!vis[k]) {
                        vis[i] = vis[j] = vis[k] = 1;
                        fill(n, t-1, min(s, a[i][j]+a[i][k]+a[k][j]), m | (1<<i) | (1<<j) | (1<<k), v);
                        vis[i] = vis[j] = vis[k] = 0;
                    }
    }
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc){
        int n;
        scanf("%d", &n);
        memset(vl, -1, sizeof(vl));
        memset(vr, -1, sizeof(vr));
        for (int i = 0; i < 3*n; ++i)
            for (int j = 0; j < 3*n; ++j)
                scanf("%d",&a[i][j]);

        int l = n/2, r = n-l;
        fill(3*n, l, INF, 0, vl);
        fill(3*n, r, INF, 0, vr);
        int ans = 0;
        for (int i = 0; i < (1<<(3*n)); ++i) {
            int neg = (1<<(3*n))-i-1;
            if (vl[i] == -1 && vr[neg] == -1) continue;
            ans = max(ans, min(vl[i],vr[neg]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
