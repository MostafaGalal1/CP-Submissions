#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;
        char ch;
        bool done = false;
        vector<ll> a(n);
        string days[5];
        ll cnt[5] = {0,0,0,0,0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> ch;
                days[j] += ch;
                if (ch == '1')
                    cnt[j]++;
            }
        }

        vector<string> ve;
        for (int i = 0; i < 5; ++i) {
            if (cnt[i] >= n/2){
                ve.push_back(days[i]);
            }
        }

        if (ve.size() < 2){
            cout << "NO";
        } else {
            for (int i = 0; i < ve.size() && !done; ++i) {
                for (int j = i+1; j < ve.size() && !done; ++j) {
                    string s(n, '0'), rs(n, '1');
                    for (int k = 0; k < n; ++k) {
                        if (ve[i][k] == '1' || ve[j][k] == '1'){
                            s[k] = '1';
                        }
                    }
                    if (s == rs){
                        done = true;
                        break;
                    }
                }
            }

            if (done)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
    return 0;
}