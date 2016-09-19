#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string s;
        cin >> s;
        int one = 0, zero = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '0') ++zero;
            else ++one;
        }
        if (one == 1 || zero == 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
