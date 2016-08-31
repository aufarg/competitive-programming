#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAXQ 100000

long long occ[MAXQ+5], ans[MAXN+5];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    stack<long long> S;
    S.push(n);
    for (int i = 0; i < q; ++i) {
        long long a;
        scanf("%lld", &a);
        while (!S.empty() && S.top() >= a) {
            S.pop();
        }
        S.push(a);
    }

    vector<long long> op;
    while (!S.empty()) {
        op.push_back(S.top());
        S.pop();
    }
    reverse(op.begin(), op.end());

    occ[op.size()-1] = 1;
    for (int i = op.size()-1; i >= 0; --i) {
        long long k = op[i];
        int upper = i-1;
        int ok = 1;
        while (ok && upper >= 0) {
            ok = 0;
            int l = 0, r = upper;
            while (l < r) {
                int m = (l+r)/2;
                if (k < op[m]) {
                    r = m-1;
                }
                else {
                    l = m+1;
                }
            }
            for (; l+1 <= upper && k >= op[l]; ++l);
            for (; l-1 >= 0 && k < op[l]; --l);
            int j = l;
            if (k >= op[j]) {
                occ[j] += occ[i] * (k/op[j]);
                k %= op[j];
                ok = 1;
            }
            upper = j-1;
        }
        ans[1] += occ[i];
        ans[k+1] -= occ[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += ans[i];
        printf("%lld\n", sum);
    }
    return 0;
}
