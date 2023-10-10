#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        int n, k, num = -1;
        cin >> n >> k;
        int a[n], b[n];

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 0; i < n; i++){
            cin >> b[i];
        }

        while(num != k){
            num = k;
            for (int i = 0; i < n; i++){
                if (a[i] <= k) {
                    k += b[i];
                    b[i] = 0;
                }
            }
        }

        cout << num << endl;
    }

    return 0;
}