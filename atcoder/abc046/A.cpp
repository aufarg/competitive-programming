#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    s.insert(a);
    s.insert(b);
    s.insert(c);
    printf("%d\n", s.size());
    return 0;
}
