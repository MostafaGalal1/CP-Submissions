#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        int m = 0;
        cin >> m;
        int sum = 0;

        for (int j = 0; j < n; j++){
            int num = 0;
            cin >> num;
            sum += num;
        }

        if (sum >= m)
            cout << (sum - m);
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
