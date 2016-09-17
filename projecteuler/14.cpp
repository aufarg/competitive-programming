#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int mem[MAXN+5];

int chain(long long x)
{
    if (x < MAXN && mem[x] >= 0) return mem[x];
    if (x == 1) return 1;
    int ret;
    if (x % 2) ret = chain(3*x+1)+1;
    else ret = chain(x/2);
    if (x < MAXN) mem[x] = ret;
    return ret;
}

int main()
{
    int ans = 0;
    int maxlen = 0;
    memset(mem, -1, sizeof(mem));
    for (int i = 1; i < 1000000; ++i) {
        int len = chain(i);
        if (len > maxlen) {
            maxlen = len;
            ans = i;
        }
    }
    printf("%d\n", ans);
}
