#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int len, ntc;
    cin >> len >> ntc;
    int w[len+5];
    for (int i = 0; i < len; ++i) {
        cin >> w[i];
    }
    int c[5][len+5];
    for (int k = 3; k >= 1; --k) {
        for (int i = 0; i < len; ++i) {
            if (w[i] >= k) { 
                if (!i || c[k][i-1] == len) {
                    c[k][i] = i;
                }
                else {
                    c[k][i] = c[k][i-1];
                }
            }
            else {
                c[k][i] = len;
            }
        }
    }

    for (int i = 0; i < ntc; ++i) {
        int l, r;
        cin >> l >> r;
        for (int k = 3; k >= 1; --k) {
            if (c[k][r] <= l) {
                cout << k << endl;
                break;
            }
        }
    }
}
