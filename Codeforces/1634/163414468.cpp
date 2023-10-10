#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        long long n, x, y, sum;
        cin >> n >> x >> y;
        sum = x;

        for (long long i = 0; i < n; i++) {
            long long num;
            cin >> num;
            sum += num;
        }

        if (sum%2 == y%2)
            cout << "Alice";
        else
            cout << "Bob";
        cout << endl;
    }

    return 0;
}