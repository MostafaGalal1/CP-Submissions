#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;
    while(t --> 0) {
        string s;
        cin >> s;
        ll n = (ll)s.length();
        map<char, ll> mapp;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            mapp[s[i]]++;
            a[i] = mapp[s[i]];
        }

        ll ind = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == mapp[s[i]]){
                ind = i;
                break;
            }
        }

        cout << s.substr(ind, (ll)s.length() - ind) << endl;
    }

    return 0;
}