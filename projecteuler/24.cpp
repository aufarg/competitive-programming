#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 1; i < 1000000; ++i) {
        next_permutation(a,a+10);
    }
    for (int i = 0; i < 10; ++i) printf("%d", a[i]);
    return 0;
}
