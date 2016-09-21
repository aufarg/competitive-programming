#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define MAXV 10000000

int main()
{
    string s;
    while (cin >> s) {
        if (s[0] == 'e') break;
        if (s[0] == 't') {
            int j = 3;
            int b = 0;
            while (j < s.size()) {
                b = b*10 + s[j]-'0';
                ++j;
            }
            long long n;
            cin >> n;
            int sgn = (n < 0);
            if (n == 0) {
                puts("0");
                continue;
            }
            if (n < 0) n = -n;
            vector<int> repr;
            while (n) {
                repr.push_back(n % b);
                n /= b;
            }
            for (int i = 0; i < repr.size(); ++i) {
                if (i%2!=sgn && repr[i] > 0) repr[i] += 2*(b-repr[i]);
                if (repr[i] >= b) {
                    if (i+1 < repr.size()) repr[i+1] += repr[i]/b;
                    else repr.push_back(repr[i]/b);
                    repr[i] %= b;
                }
            }
            for (int i = repr.size()-1; i >= 0; --i) {
                printf("%d", repr[i]);
            }
            puts("");
        }
        if (s[0] == 'f') {
            int j = 5;
            int b = 0;
            while (j < s.size()) {
                b = b*10 + s[j]-'0';
                ++j;
            }
            b = -b;

            string n;
            cin >> n;
            long long d = 0;
            for (int i = 0; i < n.size(); ++i) {
                d = d*b + n[i]-'0';
            }
            cout << d << endl;
        }
    }
    return 0;
}
