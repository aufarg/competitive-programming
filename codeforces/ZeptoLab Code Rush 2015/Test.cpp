#include <iostream>

using namespace std;

int main() {
    long long C, Hr, Hb, Wr, Wb;
    long long ans = 0; 
    cin >> C >> Hr >> Hb >> Wr >> Wb;
    for (long long i = 0; i * Wr <= C; ++i) {
        long long small = (C - i * Wr) / Wb;
        ans = max(ans, i * Hr + small * Hb);
    }
    cout << ans << endl;
}
