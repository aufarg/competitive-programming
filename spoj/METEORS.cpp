#include <bits/stdc++.h>

using namespace std;

#define MAXM 300000
#define MAXN 300000
#define MAXK 300000

struct BIT {
    long long f[MAXM+5];
    BIT() {
        this->reset();
    }

    void reset() {
        for (int i = 0; i <= MAXM; ++i) f[i] = 0;
    }

    long long query(int v) {
        long long ret = 0;
        for (; v; v-=v&(-v)) {
            ret += f[v];
        }
        return ret;
    }
    void update(int v, long long c) {
        for (; v <= MAXM; v+=v&(-v)) {
            f[v] += c;
        }
    }
};

int n, m, k;
int hi[MAXN+5], lo[MAXN+5], need[MAXN+5];
int l[MAXK+5], r[MAXK+5], a[MAXK+5];
vector<int> check[MAXK+5], sect[MAXN+5];

int terminated()
{
    for (int i = 1; i <= n; ++i) {
        if (lo[i] < hi[i]) return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int s;
        scanf("%d", &s);
        sect[s].push_back(i);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &need[i]);
    scanf("%d", &k);
    for (int q = 0; q < k; ++q) {
        scanf("%d%d%d", &l[q], &r[q], &a[q]);
    }

    for (int i = 1; i <= n; ++i) {
        lo[i] = 0;
        hi[i] = k;
    }
    BIT bit;
    while (!terminated()){
        // clear tree
        bit.reset();

        // generate new check
        for (int i = 1; i <= n; ++i) {
            int mid = (lo[i]+hi[i])/2;
            check[mid].push_back(i);
        }

        for (int q = 0; q < k; ++q) {
            // apply query
            if (l[q] <= r[q]) {
                bit.update(l[q], a[q]);
                bit.update(r[q]+1, -a[q]);
            }
            else {
                bit.update(l[q], a[q]);
                bit.update(1, a[q]);
                bit.update(r[q]+1, -a[q]);
            }

            // check
            for (auto &v: check[q]) {
                long long sum = 0;
                for (auto &s: sect[v]) {
                    sum += bit.query(s);
                    if (sum >= need[v]) break;
                }
                if (sum >= need[v]) {
                    hi[v] = q;
                }
                else {
                    lo[v] = q+1;
                }
            }
            check[q].clear();
        }

    }

    for (int i = 1; i <= n; ++i) {
        if (lo[i] < k) printf("%d\n", lo[i]+1);
        else puts("NIE");
    }

    return 0;
}
