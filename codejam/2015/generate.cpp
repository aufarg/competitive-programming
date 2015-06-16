#include <iostream>

using namespace std;

int main() {
    cout << 100 << endl;
    for (int tc = 0; tc < 100; ++tc) {
        cout << 10000 << " " << 1 << endl;
        string s;
        for (int i = 0; i < 10000; ++i) {
            s += (char)((int)('i') + i % 3);
        }
        cout << s << endl;
    }
}
