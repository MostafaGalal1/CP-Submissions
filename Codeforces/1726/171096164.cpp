#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t-->0){
        ll n, m;
        cin >> n;
        cin >> m;

        if ((n%2 == 0 && m%2 == 1) || n > m)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            if (n%2){
                for (int i = 0; i < n-1; ++i) {
                    cout << 1 << ' ';
                }
                cout << m - (n-1) << endl;
            } else {
                for (int i = 0; i < n-2; ++i) {
                    cout << 1 << ' ';
                }
                cout << (m - (n-2)) / 2 << ' ' << (m - (n-2)) / 2 << endl;
            }
        }
    }

    return 0;
}