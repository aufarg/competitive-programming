#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int kmp[MAXN+5];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    kmp[0] = -1;
    for (int i = 0; i < n; ++i) {
        int j = kmp[i];
        while (j > -1 && s[j+1] != s[i+1]) j = kmp[j];
        if (s[j+1] == s[i+1]) ++j;
        kmp[i+1] = j;
    }
    int k = kmp[n-1];
    int mx = -1;
    for (int i = 1; i < n-1; ++i) mx = max(mx, kmp[i]);
    while (k > mx) k = kmp[k];
    if (k > -1) {
        for (int i = 0; i <= k; ++i) printf("%c", s[i]);
        puts("");
    }
    else puts("Just a legend");

    return 0;
}
