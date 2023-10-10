#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        bool done = false;
        ll n, zeros = 0;
        cin >> n;
        vector<ll> arr(n), pre(n), zer(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            pre[i] = arr[i];
            if (i > 0)
                pre[i] += pre[i-1];
        }

        for (int i = 0; i < n; ++i) {
            if (!arr[i])
                zeros++;
            zer[i] = zeros;
        }

        set<ll> s;
        for (int i = 0; i < n; ++i) {
            s.clear();
            for (int j = i+1; j < n; ++j) {
                if (arr[j] < arr[i])
                    s.insert(arr[j]);
                if ((arr[j] == arr[i]) || (pre[j] - pre[i] == arr[i] * (arr[i] - 1) / 2 && zer[j] - zer[i] == 2 && s.size() == arr[i])) {
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }

        if (done){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}