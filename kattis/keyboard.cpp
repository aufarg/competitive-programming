#include <bits/stdc++.h>

using namespace std;

#define MAXN 50
#define MAXL 10000
struct State
{
    int r, c, x, d;
    State(int _r, int _c, int _x, int _d): r(_r), c(_c), x(_x), d(_d) {};
};

int vis[MAXN+5][MAXN+5][MAXL+5], grid[MAXN+5][MAXN+5];
int rnext[MAXN+5][MAXN+5][8], cnext[MAXN+5][MAXN+5][8]; 
char t[MAXL+5];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

int main()
{
    int r, c;
    scanf("%d%d", &r,&c);
    for (int i = 1; i <= r; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= c; ++j) grid[i][j] = s[j-1];
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int d = 0; d < 4; ++d) {
                int ti = i, tj = j;
                while (grid[ti][tj] == grid[i][j]) ti += dr[d], tj += dc[d];
                rnext[i][j][d] = ti; cnext[i][j][d] = tj;
            }
        }
    }
    scanf("%s", &t);
    int len = strlen(t)+1;
    t[len-1] = '*';

    queue<State> Q;
    Q.push(State(1, 1, 0, 0));
    while (!Q.empty()) {
        int rr = Q.front().r;
        int cc = Q.front().c;
        int idx = Q.front().x;
        int d = Q.front().d;
        Q.pop();
        if (idx == len) {
            printf("%d\n", d);
            break;
        }
        if (!vis[rr][cc][idx+1] && t[idx] == grid[rr][cc]) {
            vis[rr][cc][idx+1] = true;
            Q.push(State(rr, cc, idx+1, d+1));
        }
        for (int i = 0; i < 4; ++i) {
            int nr = rnext[rr][cc][i], nc = cnext[rr][cc][i];
            if (1 <= nr && nr <= r && 1 <= nc && nc <= c) {
                if (!vis[nr][nc][idx]) {
                    vis[nr][nc][idx] = true;
                    Q.push(State(nr,nc,idx,d+1));
                }
            }
        }
    }
}
