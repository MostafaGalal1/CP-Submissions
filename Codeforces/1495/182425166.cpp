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

    while (t --> 0){
        ll n;
        cin >> n;

        vector<ll> miners;
        vector<ll> mines;

        ll x, y;
        for (int i = 0; i < 2*n; ++i) {
            cin >> x >> y;
            if (!x){
                miners.push_back(abs(y));
            } else {
                mines.push_back(abs(x));
            }
        }

        sort(miners.begin(), miners.end());
        sort(mines.begin(), mines.end());

        long double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += sqrtl(miners[i] * miners[i] + mines[i] * mines[i]);
        }

        cout << setprecision(16) << sum << endl;
    }

    return 0;
}