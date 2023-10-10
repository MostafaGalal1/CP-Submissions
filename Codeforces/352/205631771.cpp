#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n), res;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    bool done = false;
    sort(a.begin(), a.end());

    ll dif = -1;
    for (int i = 0; i < n-1; ++i) {
        if (a[i].first == a[i+1].first){
            if (dif == -1)
                dif = a[i+1].second - a[i].second;
            else {
                if (a[i+1].second - a[i].second != dif)
                    done = true;
            }
        } else {
            if (!done)
                res.emplace_back(a[i].first, (dif==-1?0:dif));
            done = false;
            dif = -1;
        }
    }
    if (!done)
        res.emplace_back(a[n-1].first, (dif==-1?0:dif));

    cout << (ll)res.size() << endl;
    for (int i = 0; i < (ll)res.size(); ++i) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}