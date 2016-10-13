#include <bits/stdc++.h>

using namespace std;

int cnt[30];
bool friends(string s, string t)
{
    if (s[0] == '0' || t[0] == '0') return false;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); ++i) cnt[s[i]-'0'] = 1;
    for (int i = 0; i < t.size(); ++i) if (cnt[t[i]-'0'] == 0) return false;
    for (int i = 0; i < t.size(); ++i) cnt[t[i]-'0'] = 0;
    for (int i = 0; i < s.size(); ++i) if (cnt[s[i]-'0'] == 1) return false;
    return true;
}

bool almost(string s, string t)
{
    for (int i = 0; i+1 < s.size(); ++i) {
        s[i]++;
        s[i+1]--;
        if (isdigit(s[i]) && isdigit(s[i+1]) && friends(s, t)) return true;
        s[i]-=2;
        s[i+1]+=2;
        if (isdigit(s[i]) && isdigit(s[i+1]) && friends(s, t)) return true;
        s[i]++;
        s[i+1]--;
    }
    return false;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string s, t;
        cin >> s >> t;
        if (friends(s, t)) {
            puts("friends");
            continue;
        }
        else if (almost(s, t) || almost(t, s)) {
            puts("almost friends");
        }
        else puts("nothing");
    }
    return 0;
}
