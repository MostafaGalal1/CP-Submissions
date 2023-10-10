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

    while (t --> 0){
        ll n, m, x, y, cnt = 0;
        cin >> n >> m;
        map<ll, ll> mapp;
        map<pair<ll, ll>, bool> mo;

        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            if (x == y){
                cnt--;
                continue;
            }

            mapp[x] = y;
        }

        for (auto & mm : mapp){
            ll cur = mm.second;
            while (mapp[cur] && !mo[{cur, mapp[cur]}]){
                mo[{cur, mapp[cur]}] = true;
                if (mapp[cur] == mm.first)
                    cnt++;
                cur = mapp[cur];
            }
        }

        cout << m + cnt << endl;
    }

    return 0;
}