#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main() {

    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        ll n, mxa = 0, mnb = LONG_LONG_MAX, mxb = 0, mna = LONG_LONG_MAX;
        cin >> n;

        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mxa = max(mxa, a[i]);
            mna = min(mna, a[i]);
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            mxb = max(mxb, b[i]);
            mnb = min(mnb, b[i]);
        }

        if (mxa <= mnb){
            for (int i = 0; i < n; ++i) {
                cout << mnb - a[i] << ' ';
            }
            cout << endl;
            for (int i = 0; i < n; ++i) {
                cout << mxb - a[i] << ' ';
            }
            cout << endl;
        } else {

            stack<ll> s;

            sort(b.begin(), b.end());
            for (int i = n-1; i >= 0; --i) {
                ll it = *lower_bound(b.begin(), b.end(), a[i]);
                s.push(it - a[i]);
            }

            ll sz = s.size();

            for (int i = 0; i < sz; ++i) {
                cout << s.top() << ' ';
                s.pop();
            }
            cout << endl;

            auto yy = b.end();
            s.push(mxb - a[n-1]);
            for (int i = n-2; i >= 0; --i) {
                auto it = lower_bound(b.begin(), b.end(), a[i+1]);
                if (b.end() - it == n - 1 - i){
                    s.push(b[it - b.begin() - 1] - a[i]);
                    yy = it;
                } else {
                    s.push(b[yy - b.begin() - 1] - a[i]);
                }
            }

            sz = s.size();
            for (int i = 0; i < sz; ++i) {
                cout << s.top() << ' ';
                s.pop();
            }
            cout << endl;

        }
    }
    return 0;
}
