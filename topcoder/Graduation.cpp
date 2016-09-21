#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define MAXN 500
#define NCLASS 126-33+1

int codes[MAXN+5], rev[MAXN+5];
int res[MAXN+5][MAXN+5];
int p[MAXN+5];
int vis[MAXN+5];

class Graduation
{
    public:
        int maxflow(int n, int s, int t)
        {
            int ok = 1;
            int mf = 0;
            while (ok) {
                ok = 0;
                int f = INF;
                memset(vis, 0, sizeof(vis));
                queue<pair<int,int> > Q;
                Q.push(make_pair(s, f));
                vis[s] = 1;
                while (!Q.empty()) {
                    int v = Q.front().first;
                    int cf = Q.front().second;
                    Q.pop();
                    if (v == t) f = cf;
                    for (int u = 0; u < n; ++u) {
                        int c = res[v][u];
                        if (!vis[u] && c > 0) {
                            Q.push(make_pair(u, min(c, cf)));
                            vis[u] = 1, p[u] = v;
                        }
                    }
                }
                if (f != INF) {
                    ok = 1;
                    mf += f;
                    int v = t;
                    while (v != s) {
                        int u = p[v];
                        res[v][u] += f;
                        res[u][v] -= f;
                        v = u;
                    }
                }
            }
            return mf;
        }
        string moreClasses(string taken, vector<string> reqs)
        {
            string ret = "";
            sort(ret.begin(), ret.end());
            int n = reqs.size()+2;
            int s = reqs.size(), t = reqs.size()+1;
            memset(codes, -1, sizeof(codes));
            for (int i = 0; i < taken.size(); ++i) {
                codes[taken[i]-33] = n;
                rev[n] = taken[i];
                ++n;
            }
            int maxtaken = n;
            for (int i = 0; i < NCLASS; ++i) {
                if (codes[i] == -1) {
                    codes[i] = n;
                    rev[n] = i+33;
                    ++n;
                }
            }

            int nreq = 0;
            for (int i = 0; i < reqs.size(); ++i) {
                string req = reqs[i];
                int j = 0;
                int c = 0;
                int v = i;
                while (j < req.size() && isdigit(req[j])) {
                    c = c*10+req[j]-'0';
                    ++j;
                }
                nreq += c;
                res[s][v] = c;
                while (j < req.size()) {
                    int u = codes[req[j]-33];
                    res[v][u] = 1; res[u][t] = 1;
                    ++j;
                }
            }
            int mf = maxflow(maxtaken, s, t);
            for (int i = 1; i <= NCLASS; ++i) {
                int f = maxflow(maxtaken+i, s, t);
                if (f > 0) {
                    ret += rev[maxtaken+i-1];
                }
                mf += f;
                if (mf == nreq) {
                    return ret;
                }
            }
            return "0";
        }
};
