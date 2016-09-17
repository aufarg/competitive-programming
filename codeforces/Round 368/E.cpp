#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000
#define MAXM 2000
#define MAXK 2000
#define MAXQ 1000000

int n,m,k,q;
int len[MAXK+5];
int r[MAXN+5][MAXM+5], c[MAXN+5][MAXM+5], p[MAXN+5][MAXM+5];
int on[MAXK+5];
int g[MAXQ+5];
int x1[MAXQ+5], yy1[MAXQ+5], x2[MAXQ+5], y2[MAXQ+5];
long long ans[MAXK+5][MAXK+5];
int qt[MAXQ+5];

struct BIT {
    long long f[MAXN+5][MAXM+5];
    BIT() {
        for (int i = 0; i <= MAXN; ++i) {
            for (int j = 0; j <= MAXM; ++j) {
                f[i][j] = 0;
            }
        }
    }

    long long query(int x, int y) {
        long long ret = 0;
        for (; x; x-=x&(-x))
            for (int yy = y; yy; yy-=yy&(-yy))
                ret += f[x][yy];
        return ret;
    }

    void update(int x, int y, long long c) {
        for (; x <= MAXN; x+=x&(-x))
            for (int yy = y; yy <= MAXM; yy+=yy&(-yy))
                f[x][yy] += c;
    }

};

BIT bit;

long long query(int x1, int yy1, int x2, int y2)
{
    return bit.query(x2,y2)-bit.query(x1-1,y2)-bit.query(x2,yy1-1)+bit.query(x1-1,yy1-1);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; ++j) {
            scanf("%d%d%d", &r[i][j], &c[i][j], &p[i][j]);
        }
        on[i] = 1;
    }

    scanf("%d", &q);
    vector<int> asks;
    char cmd[256];
    int id = 0;
    for (int qq = 0; qq < q; ++qq) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "SWITCH")) {
            qt[qq] = 0;
            scanf("%d", &g[qq]);
            --g[qq];
        }
        else {
            qt[qq] = 1;
            asks.push_back(id);
            scanf("%d%d%d%d", &x1[id], &yy1[id], &x2[id], &y2[id]);
            ++id;
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < len[i]; ++j) {
            bit.update(r[i][j], c[i][j], p[i][j]);
        }
        for (auto &j: asks) {
            ans[i][j] = query(x1[j], yy1[j], x2[j], y2[j]);
        }
        for (int j = 0; j < len[i]; ++j) {
            bit.update(r[i][j], c[i][j], -p[i][j]);
        }
    }

    id = 0;
    for (int qq = 0; qq < q; ++qq) {
        if (qt[qq]) {
            long long sum = 0;
            for (int i = 0; i < k; ++i) {
                if (on[i]) {
                    sum += ans[i][id];
                }
            }
            cout << sum << endl;
            ++id;
        }
        else {
            on[g[qq]] = !on[g[qq]];
        }
    }
    return 0;
}
