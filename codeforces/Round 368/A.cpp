#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char buf[5];
            scanf("%s", buf);
            switch (buf[0]) {
                case 'C':
                case 'M':
                case 'Y':
                    goto fail;
            }
        }
    }
    puts("#Black&White");
    return 0;
fail:
    puts("#Color");
    return 0;
}
