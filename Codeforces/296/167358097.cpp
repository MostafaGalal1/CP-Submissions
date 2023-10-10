#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 510;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, intermediate, tot;

    cin >> n;

    ll arr[n][n];
    stack<ll> st, rs;
    vector<ll> ve;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> intermediate, intermediate--;
        st.push(intermediate);
    }

    for (ll k = 0; k < n; ++k) {
        tot = 0;
        intermediate = st.top(), st.pop();
        ve.push_back(intermediate);
        sort(ve.begin(), ve.end());
        for (ll i = 0; i < n; i++) {
            for (ll j= 0; j < n; j++ ) {
                if (arr[i][j] > arr[i][intermediate] + arr[intermediate][j])
                    arr[i][j] = arr[i][intermediate] + arr[intermediate][j];
            }
        }
        for (ll i : ve) {
            for (ll j : ve) {
                tot += arr[i][j];
            }
        }
        rs.push(tot);
    }

    for (int i = 0; i < n; ++i) {
        cout << rs.top() << ' ', rs.pop();
    }

    cout << endl;

    return 0;
}