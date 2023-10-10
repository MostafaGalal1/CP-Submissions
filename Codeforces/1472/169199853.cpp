#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while(t --> 0) {
        unordered_map<int, int> mapp;
        int n, num;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            mapp[num]++;
        }

        if (((mapp[1] + mapp[2] * 2) % 4 == 0) || (mapp[1]%2 == 0 && mapp[1] > 1))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return  0;
}
