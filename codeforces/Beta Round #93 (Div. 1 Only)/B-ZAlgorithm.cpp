#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int Z[MAXN+5];

int main()
{
    string s;
    cin >> s;
    int L = 0, R = 0;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R-L]) ++R;
            Z[i] = R-L; --R;
        }
        else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R] == s[R-L]) ++R;
                Z[i] = R-L; --R;
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (Z[i] == n-i && mx >= n-i) {
            for (; i < n; ++i) printf("%c", s[i]);
            puts("");
            goto ok;
        }
        mx = max(mx, Z[i]);
    }
    puts("Just a legend");
ok:
    return 0;
}
