#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string s;
        cin >> s;
        int l = 0, r = s.size()-1;
        while (l <= r) {
            if (s[l] == '.' && s[r] == '.') s[l] = s[r] = 'a';
            else if (s[l] == '.') s[l] = s[r];
            else if (s[r] == '.') s[r] = s[l];
            else if (s[l] != s[r]) goto error;
            ++l;
            --r;
        }
        cout << s << endl;
        continue;
error:
        puts("-1");
    }
    return 0;
}
