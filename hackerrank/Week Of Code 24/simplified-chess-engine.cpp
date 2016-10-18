#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > vcc;

set<vcc> vis;
int w, b, m;

bool ok(int r, int c) {
    return (0 <= r && r < 4 && 0 <= c && c < 4);
}

bool dfs(vcc grid, int move) {
    if ( move > m ) return false;
    bool ret = true;
    int sgn = (move&1) ? 1: -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j]*sgn > 0) {
                switch (grid[i][j]) {
                    case 'Q':
                    case -'Q':
                        {
                            int dr[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
                            int dc[] = { -1, 0, 1, -1, 0, 1, 1, -1 };
                            for (int d = 0; d < 8; ++d) {
                                bool done = false;
                                for (int c = 1; !done && c < 4; ++c) {
                                    int nr = i+c*dr[d], nc = j+c*dc[d];
                                    if (!ok(nr, nc)) break;
                                    /* printf("%d %d %d %d %d %d %d %d\n", move, d, i, j, nr, nc, grid[1][3], grid[nr][nc]); */
                                    if (grid[nr][nc] == -'Q' && sgn > 0) return true;
                                    if (grid[nr][nc] == 'Q' && sgn < 0) return false;
                                    vcc ngrid = grid;
                                    if (grid[nr][nc]*sgn < 0) {
                                        ngrid[nr][nc] = grid[i][j];
                                        ngrid[i][j] = 0;
                                        done = true;
                                    }
                                    else if (grid[nr][nc]*sgn == 0) {
                                        swap(ngrid[nr][nc], ngrid[i][j]);
                                    }
                                    else break;
                                    bool ret = dfs(ngrid, move+1);
                                    if (sgn < 0 && !ret) return false;
                                    if (sgn > 0 && ret) return true;
                                }
                            }
                            break;
                        }
                    case 'N':
                    case -'N':
                        {
                            int dr[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
                            int dc[] = { -1, 1, -2, 2, -1, 1, -2, 2 };
                            for (int d = 0; d < 8; ++d) {
                                int nr = i+dr[d], nc = j+dc[d];
                                if (!ok(nr, nc)) continue;
                                if (grid[nr][nc] == -'Q' && sgn > 0) return true;
                                if (grid[nr][nc] == 'Q' && sgn < 0) return false;
                                vcc ngrid = grid;
                                if (grid[nr][nc]*sgn < 0) {
                                    ngrid[nr][nc] = grid[i][j];
                                    ngrid[i][j] = 0;
                                }
                                else if (grid[nr][nc]*sgn == 0) {
                                    swap(ngrid[nr][nc], ngrid[i][j]);
                                }
                                else continue;
                                bool ret = dfs(ngrid, move+1);
                                if (sgn < 0 && !ret) return false;
                                if (sgn > 0 && ret) return true;
                            }
                            break;
                        }
                    case 'B':
                    case -'B':
                        {
                            int dr[] = { 1, 1, -1, -1 };
                            int dc[] = { -1, 1, -1, 1 };
                            for (int d = 0; d < 4; ++d) {
                                bool done = false;
                                for (int c = 1; !done && c < 4; ++c) {
                                    int nr = i+c*dr[d], nc = j+c*dc[d];
                                    if (!ok(nr, nc)) break;
                                    if (grid[nr][nc] == -'Q' && sgn > 0) return true;
                                    if (grid[nr][nc] == 'Q' && sgn < 0) return false;
                                    vcc ngrid = grid;
                                    if (grid[nr][nc]*sgn < 0) {
                                        ngrid[nr][nc] = grid[i][j];
                                        ngrid[i][j] = 0;
                                        done = true;
                                    }
                                    else if (grid[nr][nc]*sgn == 0) {
                                        swap(ngrid[nr][nc], ngrid[i][j]);
                                    }
                                    else break;
                                    bool ret = dfs(ngrid, move+1);
                                    if (sgn < 0 && !ret) return false;
                                    if (sgn > 0 && ret) return true;
                                }
                            }
                            break;
                        }
                    case 'R':
                    case -'R':
                        {
                            int dr[] = { 1, -1, 0, 0 };
                            int dc[] = { 0, 0, 1, -1 };
                            for (int d = 0; d < 4; ++d) {
                                bool done = false;
                                for (int c = 1; !done && c < 4; ++c) {
                                    int nr = i+c*dr[d], nc = j+c*dc[d];
                                    /* printf("%d %d\n", nr, nc); */
                                    if (!ok(nr, nc)) break;
                                    if (grid[nr][nc] == -'Q' && sgn > 0) return true;
                                    if (grid[nr][nc] == 'Q' && sgn < 0) return false;
                                    vcc ngrid = grid;
                                    if (grid[nr][nc]*sgn < 0) {
                                        ngrid[nr][nc] = grid[i][j];
                                        ngrid[i][j] = 0;
                                        done = true;
                                    }
                                    else if (grid[nr][nc]*sgn == 0) {
                                        swap(ngrid[nr][nc], ngrid[i][j]);
                                    }
                                    else break;
                                    bool ret = dfs(ngrid, move+1);
                                    if (sgn < 0 && !ret) return false;
                                    if (sgn > 0 && ret) return true;
                                }
                            }
                            break;
                        }
                }
            }
        }
    }
    return sgn < 0;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d%d%d", &w, &b, &m);
        vcc grid;
        grid.push_back(vector<char>(4));
        grid.push_back(vector<char>(4));
        grid.push_back(vector<char>(4));
        grid.push_back(vector<char>(4));
        for (int i = 0; i < w; ++i) {
            char t, c;
            int r;
            scanf(" %c %c%d", &t, &c, &r);
            --r;
            grid[c-'A'][r] = t;
        }
        for (int i = 0; i < b; ++i) {
            char t, c;
            int r;
            scanf(" %c %c%d", &t, &c, &r);
            --r;
            grid[c-'A'][r] = -t;
        }
        puts(dfs(grid, 1) ? "YES" : "NO");
    }
    return 0;
}
