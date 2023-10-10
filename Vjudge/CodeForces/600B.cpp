#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, m, num;
    cin >> n >> m;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; ++i) {
        cin >> num;
        auto it = upper_bound(a.begin(), a.end(), num);
        cout << (it - a.begin()) << " ";
    }

    cout << endl;
    return 0;
}