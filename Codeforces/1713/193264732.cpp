#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        ll n;
        bool done = false;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        bool tr = false;
        for (int i = 1; i < n-1; ++i) {
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                done = true;
                break;
            }

            if (tr){
                if (arr[i + 1] < arr[i])
                    tr = false;
                else if (arr[i + 1] > arr[i]){
                    done = true;
                    break;
                }
            }

            if (arr[i] < arr[i - 1] && arr[i] == arr[i + 1]) {
                tr = true;
            }
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }

    return 0;
}
