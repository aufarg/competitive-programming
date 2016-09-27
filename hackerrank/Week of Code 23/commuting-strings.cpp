#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MOD 1000000007
#define MAXN 5000000

char s[MAXN+5];
int m;
int kmp[MAXN+5];

int main()
{
    scanf("%s%d", s, &m);
    int n = strlen(s);

    kmp[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = kmp[i-1];
        while (j > 0 && s[i] != s[j]) j = kmp[j-1];
        if (s[i] == s[j]) ++j;
        kmp[i] = j;
    }

    int ans = (m/n);
    int j = kmp[n-1];
    while (j > 0) {
        if (j <= m) ans += (m-j)/n+1;
        j = kmp[j-1];
    }
    printf("%d\n", ans % MOD);
    return 0;
}
