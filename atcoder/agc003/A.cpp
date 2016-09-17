#include <bits/stdc++.h>

using namespace std;

int a[5];
int main()
{
    string s;
    cin >> s;
    int axis = 0, ord = 0;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case 'E':
                if (!a[0]) {
                    axis = !axis;
                }
                a[0] = 1;
                break;
            case 'W':
                if (!a[1]) {
                    axis = !axis;
                }
                a[1] = 1;
                break;
            case 'N':
                if (!a[2]) {
                    ord = !ord;
                }
                a[2] = 1;
                break;
            case 'S':
                if (!a[3]) {
                    ord = !ord;
                }
                a[3] = 1;
                break;
        }
    }
    if (axis || ord) puts("No");
    else puts("Yes");
}
