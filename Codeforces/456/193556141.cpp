#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    string n;
    cin >> n;
    ll len = (ll)n.length();
    if (((n[len-1] == '0' || n[len-1] == '4' || n[len-1] == '8') && (len == 1 || n[len - 2]%2 == 0)) || ((n[len-1] == '2' || n[len-1] == '6') && (len > 1 && n[len - 2]%2)))
        cout << 4;
    else
        cout << 0;
    cout << endl;

    return 0;
}
