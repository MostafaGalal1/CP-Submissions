#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, k;
        string s, res;
        cin >> n >> k >> s;

        vector<ll> se(26);

        for (int i = 0; i < n; ++i)
            se[s[i] - 'a']++;

        for (int i = 0; i < k; ++i) {
            ll cnt = 0;
            bool done = false;
            for (int j = 0; j < n/k && j < 25 && !done; ++j) {
                if (se[j] > 0){
                    se[j]--;
                    cnt++;
                } else if (!done){
                    char ch = cnt+'a';
                    res += min(ch, 'z');
                    done = true;
                }
            }

            if (!done)
                res += cnt+'a';
        }

        cout << res << endl;
    }
}