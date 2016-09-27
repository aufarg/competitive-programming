#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int kmp[MAXN+5];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    kmp[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = kmp[i-1];
        while (j > 0 && s[i] != s[j]) j = kmp[j-1];
        if (s[i] == s[j]) ++j;
        kmp[i] = j;
    }
    int k = kmp[n-1];
    int mx = 0;
    for (int i = 1; i < n-1; ++i) mx = max(mx, kmp[i]);
    while (k > mx) k = kmp[k-1];
    if (k > 0) {
        for (int i = 0; i < k; ++i) printf("%c", s[i]);
        puts("");
    }
    else puts("Just a legend");

    return 0;
}
