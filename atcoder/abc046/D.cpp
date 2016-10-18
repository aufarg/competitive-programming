#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i%2 && s[i] == 'g') ++ans;
        if (i%2 == 0 && s[i] == 'p') --ans;
    }
    printf("%d\n", ans);
}
