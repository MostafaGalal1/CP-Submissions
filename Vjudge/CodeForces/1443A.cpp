#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        int n, count = 0;
        cin >> n;

        for (int i = 4 + (2 * (n-1)); i <= 4 * n && count < n; i += 2){
            cout << i << " ";
            count++;
        }
        cout << endl;
    }

    return 0;
}