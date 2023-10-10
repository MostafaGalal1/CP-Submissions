#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

bool cmp(ll a, ll b) {
    return abs(a) > abs(b);
}

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, num;
        cin >> n;

        vector<ll> v, arr;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; ++i) {
            if (v[i] || (ll)arr.size() < 7)
                arr.push_back(v[i]);
        }

        n = (ll)arr.size();
        if (n < 8) {
            bool done = false;
            sort(arr.begin(), arr.end());
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    for (int k = j+1; k < n; ++k) {
                        auto it = lower_bound(arr.begin(), arr.end(), arr[i] + arr[j] + arr[k]);
                        if (it == arr.end() || *it != arr[i] + arr[j] + arr[k]){
                            cout << "NO";
                            done = true;
                            break;
                        }
                    }
                    if (done)
                        break;
                }
                if (done)
                    break;
            }

            if (!done)
                cout << "YES";
        } else
            cout << "NO";

        cout << endl;
    }

    return 0;
}