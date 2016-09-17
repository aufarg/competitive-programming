#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
int kmp[MAXN+5];

int main()
{
    int n;
    scanf("%d", &n);
    string A, B;
    cin >> A >> B;
    B += B;

    kmp[0] = -1;
    for (int i = 0; i+1 < A.size(); ++i) {
        int j = kmp[i];
        while (j > -1 && A[i+1] != A[j+1]) {
            j = kmp[j];
        }
        if (A[i+1] == A[j+1]) {
            kmp[i+1] = j+1;
        }
        else {
            kmp[i+1] = j;
        }
    }

    int j = -1;
    int length = 0;
    int ans = 0;
    for (int i = 0; i < B.size(); ++i) {
        while (j > -1 && B[i] != A[j+1]) {
            j = kmp[j];
        }
        if (B[i] == A[j+1]) {
            ++j;
        }
        if (length < j+1) {
            length = j+1;
            ans = i;
        }
        if (j+1 == n) {
            break;
        }
    }

    printf("%d\n", ans-length+1);
    return 0;
}
