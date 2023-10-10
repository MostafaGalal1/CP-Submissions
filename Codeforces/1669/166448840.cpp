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
        int n,sum = 0;
        cin >> n;
        vector<int> arr(n+1);

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        int f = 1, s = n, fc = arr[1], sc = arr[n];

        while(f != s) {
            if (fc == sc) {
                sum = f+n+1-s;
                f++;
                fc += arr[f];
            } else if (fc > sc) {
                s--;
                sc += arr[s];
            } else {
                f++;
                fc += arr[f];
            }
        }

        cout << sum << endl;
    }
    return 0;
}