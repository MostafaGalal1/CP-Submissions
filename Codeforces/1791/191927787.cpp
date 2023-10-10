#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        string s;
        bool done = false;
        cin >> n >> s;
        vector<map<char, ll>> ve(n);

        ve[0][s[0]]++;
        for (int i = 1; i < n; ++i) {
            for(auto & ch : ve[i-1]){
                ve[i][ch.first] = ch.second;
            }
            ve[i][s[i]]++;
        }

        ll mx = 0;
        for (int i = 0; i < n-1; ++i) {

            ll sz = ve[i].size();
            ll sc = 0;
            for(auto & ch : ve[n-1]) {
                if (ve[n-1][ch.first] - ve[i][ch.first] > 0){
                    sc++;
                }
                mx = max(mx, sc + sz);
            }
        }

        cout << mx << endl;
    }
    return 0;
}