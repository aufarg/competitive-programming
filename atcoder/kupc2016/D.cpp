#include <bits/stdc++.h>

using namespace std;

char c1[] = { '#', '.', '#', '.' };
char c2[] = { '.', '#', '#', '.' };

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> s1, s2, rs1, rs2;
    char resp[5];
    bool rev = false;
    for (int i = 0; i < n; ++i) {
        if (!rev) {
            bool ok = false;
            for (int t = 0; t < 4; ++t) {
                for (int k = 0; k < s1.size(); ++k) printf("%c", s1[k]);
                printf("%c\n", c1[t]);
                for (int k = 0; k < s2.size(); ++k) printf("%c", s2[k]);
                printf("%c\n", c2[t]);
                fflush(stdout);
                scanf("%s", resp);
                if (resp[0] == 'e') {
                    return 0;
                }
                else if (resp[0] == 'T') {
                    ok = true;
                    s1.push_back(c1[t]), s2.push_back(c2[t]);
                    break;
                }
            }
            if (!ok) rev = true;
        }
        if (rev) {
            for (int t = 0; t < 4; ++t) {
                printf("%c", c1[t]);
                for (int k = rs1.size()-1; k >= 0; --k) printf("%c", rs1[k]);
                for (int k = 0; k < s1.size(); ++k) printf("%c", s1[k]);
                puts("");
                printf("%c", c2[t]);
                for (int k = rs2.size()-1; k >= 0; --k) printf("%c", rs2[k]);
                for (int k = 0; k < s2.size(); ++k) printf("%c", s2[k]);
                puts("");
                fflush(stdout);
                scanf("%s", resp);
                if (resp[0] == 'e') {
                    return 0;
                }
                else if (resp[0] == 'T') {
                    rs1.push_back(c1[t]), rs2.push_back(c2[t]);
                    break;
                }
            }
        }
    }
    return 0;
}
