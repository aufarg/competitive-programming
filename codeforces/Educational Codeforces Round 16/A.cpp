#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a, b;
    scanf("%c%c", &a, &b);
    int r = b-'1', c = a-'a';
    int dr[] = { 1, 1, -1, -1, 1, -1, 0, 0 };
    int dc[] = { 1, -1, 1, -1, 0, 0, 1, -1 };
    int ans = 8;
    for (int i = 0; i < sizeof(dr)/sizeof(dr[0]); ++i) {
        if (r+dr[i] < 0 || r+dr[i] >= 8 || c+dc[i] < 0 || c+dc[i] >= 8) --ans;
    }
    printf("%d\n", ans);
    return 0;
}
