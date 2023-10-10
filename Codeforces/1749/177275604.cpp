#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin >> t;;

    while (t --> 0){
        ll n, num, x, y;
        cin >> n >> num;

        for (int i = 0; i < num; ++i) {
            cin >> x >> y;
        }

        if (n <= num){
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}