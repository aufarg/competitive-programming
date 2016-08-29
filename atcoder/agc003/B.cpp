#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        if (v%2) {
            ans += v/2;
            a.push_back(i);
        }
        else if (v > 0){
            ans += v/2-1;
            a.push_back(i);
            a.push_back(i);
        }
    }
    for (int i = 0; i+1 < a.size(); ++i) {
        if (a[i+1]-a[i] <= 1) {
            ++ans;
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}
