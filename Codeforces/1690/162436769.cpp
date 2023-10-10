#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int k = 0;
        int count = 0;
        int max = 0;
        bool done = false;
        cin >> n;
        cin >> k;
        char arr[n];

        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }

        for (int j = 0; j < k; j++){
            if (arr[j] == 'B')
                count++;
        }

        for (int j = 0; j <= n-k; j++){
            if (count > max)
                max = count;
            if (count == k) {
                cout << 0 << endl;
                done = true;
                break;
            } else {
                if (arr[j] == 'B')
                    count--;
                if (arr[j+k] == 'B')
                    count++;
            }
        }

        if (!done)
            cout << k - max << endl;
    }
    return 0;
}
