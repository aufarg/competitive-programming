#include <bits/stdc++.h>

using namespace std;

int a[50][50];

int n;
int odd = 1, even = 2, sgn = 1;

void putodd()
{
    printf("%d ", odd);
    odd += 2;
}
void puteven() 
{
    printf("%d ", even);
    even += 2;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n/2; ++i) {
        for (int j = n/2-1; j >= i; --j) puteven();
        for (int j = 0; j < 2*i+1; ++j) putodd();
        for (int j = n/2-1; j >= i; --j) puteven();
        puts("");
    }
    for (int i = 0; i < n; ++i) putodd();
    puts("");
    for (int i = n/2-1; i >= 0; --i) {
        for (int j = n/2-1; j >= i; --j) puteven();
        for (int j = 0; j < 2*i+1; ++j) putodd();
        for (int j = n/2-1; j >= i; --j) puteven();
        puts("");
    }
    return 0;
}
