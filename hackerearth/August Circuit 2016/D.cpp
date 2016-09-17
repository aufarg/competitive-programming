#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define INF 1000000000000000LL

int a[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        long long sum = 0;

        priority_queue<int> Q;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            Q.push(a);
            sum += a;
        }
        long long ans = INF;
        int cut = 0;
        while (!Q.empty()) {
            long long x = Q.top();
            Q.pop();
            if (x > 1) {
                ans = min(ans, x*n-sum+cut);
                sum = sum - x + x/2;
                Q.push(x/2);
                ++cut;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
