#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a;
        cin >> b;
        cin >> c;

        cout << a+b+c << " " << b+c << " " << c << endl ;
    }
    return 0;
}
