#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n, cnt = 0;
        map<int, int> mapp;

        cin >> n;
        int arr[n];

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            mapp[arr[i]]++;
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i])
                    cnt++;
            }
            cnt += (mapp[arr[i]] - 1);
        }

        cout << cnt << endl;
    }
}