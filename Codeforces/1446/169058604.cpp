#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, w, num, sum = 0;
        cin >> n >> w;
        vector<pair<ll, ll>> arr;

        for (int i = 0; i < n; ++i){
            cin >> num;
            if (num > w)
                continue;
            arr.emplace_back(num, i+1);
        }

        ll l = 0, r = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i].first, r++;
            if (sum >= (ll)round(w/2.0) && sum <= w)
                break;
            else if (sum > w) {
                while (sum > w)
                    sum -= arr[l].first, l++;
                if (sum >= (ll)round(w/2.0) && sum <= w)
                    break;
            }
        }

        if (sum < (ll)round(w/2.0) || sum > w)
            cout << -1;
        else {
            cout << r - l << endl;
            for (ll i = l; i < r; ++i)
                cout << arr[i].second << ' ';
        }

        cout << endl;
    }
    return  0;
}
