#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];

    if (n % 2 == 0) {
        cout << -1 << endl;
    }else{
        for (int i = 0; i < n; i++) {
            a[i] = i;
            b[i] = (i + 1) % n;
            c[i] = (a[i] + b[i]) % n;
            cout << a[i] << ' ';
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << b[i] << ' ';
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << c[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}