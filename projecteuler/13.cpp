#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
string s[MAXN+5];

int main()
{
    int n;
    while (cin >> s[n]) ++n;
    vector<int> ans;
    int carry = 0;
    for (int j = 49; j >= 0; --j) {
        int val = carry;
        for (int i = 0; i < n; ++i) {
            val += s[i][j]-'0';
        }
        carry = val / 10;
        ans.push_back(val % 10);
    }
    if (carry > 0) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
    }
    puts("");
}
