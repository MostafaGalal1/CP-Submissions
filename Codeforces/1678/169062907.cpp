#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        unordered_map<ll, ll> mapp;
        bool done = false;
        ll n, num;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            mapp[num]++;
        }

        if (mapp[0])
            cout << n-mapp[0];
        else {
            for (auto &ch: mapp) {
                if (ch.second > 1) {
                    cout << n;
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << n+1;
        }
        cout << endl;
    }
    return  0;
}
