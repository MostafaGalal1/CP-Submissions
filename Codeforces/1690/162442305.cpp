#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int max = 0;
        bool done = false;
        cin >> n;
        int a[n];
        int b[n];

        for (int j = 0; j < n; j++){
            cin >> a[j];
        }

        for (int j = 0; j < n; j++){
            int num = 0;
            cin >> num;
            b[j] = a[j] - num;
            if (b[j] > max)
                max = b[j];
        }

        for (int j = 0; j < n; j++){
            if (b[j] < max && a[j] != b[j]) {
                cout << "NO" << endl;
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES" << endl;
    }
    return 0;
}
