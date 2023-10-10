#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        cin >> n;
        cin >> m;

        cout << (long long)(m * ((m + 1 + n * (n+1))/2.0 - 1)) << endl ;
    }
    return 0;
}
