#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }

    ll res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ll mnj = a[i].second;
        ll mni = INT_MAX, mnk = INT_MAX;
        for (int j = 0; j < i; ++j) {
            if (a[j].first < a[i].first)
                mni = min(mni, a[j].second);
        }
        for (int j = i+1; j < n; ++j) {
            if (a[j].first > a[i].first)
                mnk = min(mnk, a[j].second);
        }
        res = min(res, mni + mnj + mnk);
    }

    cout << (res==INT_MAX?-1:res) << endl;

    return 0;
}