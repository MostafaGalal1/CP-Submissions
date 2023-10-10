#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <deque>

typedef long long ll;
using namespace std;

int main(){
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, num, area;
        bool done = false;
        cin >> n;
        vector<ll> arr;

        for (ll i = 0; i < 4 * n; i++) {
            cin >>  num;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());

        area = arr[0] * arr[4 * n - 1];
        for (ll i = 0; i < 2 * n; i += 2) {
            if (area != arr[i] * arr[4 * n - 1 - i] || area != arr[i+1] * arr[4 * n - 2 - i] || arr[i] != arr[i+1] || arr[4 * n - 1 -i] != arr[4 * n - 2 -i]) {
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";

        cout << endl;
    }

    return 0;
}