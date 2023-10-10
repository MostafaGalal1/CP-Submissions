#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n = 0;
vector<int> arr;

int mex() {
    vector<int> u = arr;
    sort(u.begin(), u.end());

    int nu = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] == nu) {
            if (i == n - 1 || u[i] != u[i + 1])
                nu++;
        } else{
            return nu;
        }
    }
    return nu;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t --> 0) {
        int num;
        cin >> n;

        vector<int> empty(n);
        swap(arr, empty);

        vector<int> v;
        v.clear();

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        while (true){
            num = mex();
            if (num == n) {
                bool d = false;
                for (int j = 0; j < n; ++j) {
                    if (j != arr[j]) {
                        arr[j] = num;
                        v.push_back(j);
                        d = true;
                        break;
                    }
                }
                if (!d)
                    break;
            } else {
                arr[num] = num;
                v.push_back(num);
            }
        }

        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i) {
            v[i]++;
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}