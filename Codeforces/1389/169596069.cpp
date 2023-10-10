#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        ll l, r;
        cin >> l >> r;
        if (l*2 > r)
            cout << -1 <<' ' << -1;
        else
            cout << l << ' ' << l*2;
        cout << endl;
    }
}
