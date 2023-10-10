#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        long a[n];
        long b[n];

        for (int j = 0; j < n; j++){
            cin >> a[j];
        }

        for (int j = 0; j < n; j++){
            cin >> b[j];
        }

        long time = 0;
        for (int j = 0; j < n; j++){
            if (time > a[j])
                cout << b[j] - time << " ";
            else
                cout << b[j] - a[j] << " ";
            time = b[j];
        }

        cout << endl;
    }
    return 0;
}
