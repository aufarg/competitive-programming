#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n % 2 == 0) {
        long long m = n*n/4-1;
        long long k = n*n/4+1;
        if (m < 1 || k < 1) {
            puts("-1");
        }
        else {
            cout << m << " " << k << endl;
        }
    }
    else {
        long long m = n*n/2;
        long long k = n*n/2+1;
        if (m < 1 || k < 1) {
            puts("-1");
        }
        else {
            cout << m << " " << k << endl;
        }
    }
    return 0;
}
