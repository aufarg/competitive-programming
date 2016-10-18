#include <bits/stdc++.h>

using namespace std;

bool allone(string s)
{
    for (int i = 0; i < s.size(); ++i) if (s[i] == '0') return false;
    return true;
}

int countone(string s)
{
    int ret = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '1') ++ret;
    return ret;
}

int sufone(string s)
{
    int ret = 0;
    for (int i = s.size()-1; i >= 0 && s[i] == '1'; --i) ++ret;
    return ret;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        int n;
        scanf("%d", &n);
        int ans = 1;
        if (allone(l3)) {
            if (allone(l2)) {
                if (allone(l1)) {}
                else {
                    ans += countone(l1) - sufone(l1);
                }
            }
            else {
                ans += countone(l1) + n*countone(l2) - sufone(l2);
            }
        }
        else {
            ans += countone(l1) + n*countone(l2) + countone(l3) - sufone(l3);
        }
        printf("%d\n", ans);
    }
    return 0;
}
