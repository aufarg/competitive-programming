#include <bits/stdc++.h>

using namespace std;

char board[105];
int cnt[35];
int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d%s", &n, board);
        memset(cnt, 0, sizeof(cnt));
        bool sp = false;
        for (int i = 0; i < n; ++i) {
            if (board[i] == '_') sp = true;
            else cnt[board[i]-'A']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 1) goto no;
        }
        if (!sp) {
            for (int i = 0; i < n; ++i) {
                if (i && board[i] == board[i-1]) continue;
                if (i+1 < n && board[i] == board[i+1]) continue;
                goto no;
            }
        }

        puts("YES");
        continue;
no:
        puts("NO");
    }
    return 0;
}
