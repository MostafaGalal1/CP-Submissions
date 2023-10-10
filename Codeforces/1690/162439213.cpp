#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int h1 = n/3 + 1, h2 = n/3, h3 = n/3 - 1;
        if (n%3 == 0)
            cout << h2 << " " << h1 << " " << h3 << endl;
        else if (n%3 == 1)
            cout << h2 << " " << h1+1 << " " << h3 << endl;
        else
            cout << h2+1 << " " << h1+1 << " " << h3 << endl;
    }
    return 0;
}
