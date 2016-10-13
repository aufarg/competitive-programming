#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> S;
    for (int i = 0; i < s.size(); ++i) {
        if (!S.empty() && s[i] == 'T' && S.top() == 'S') S.pop();
        else S.push(s[i]);
    }
    printf("%d\n", S.size());
    return 0;
}
