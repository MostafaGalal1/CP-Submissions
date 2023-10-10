#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        ll p;
        cin >> p;
        if (p%2)
            cout << 2 <<' ' << p-1;
        else
            cout << 2 << ' ' << p;
        cout << endl;
    }
}
