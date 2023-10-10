#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n, sz, q, l, r, p, res, k, mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    cin >> n >> k;

    sz = (ll)log2(n)+1;
    ll spar[sz][n], logging[n+1];

    logging[0] = logging[1] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> spar[0][i];
        mx = max(mx, spar[0][i]);
        mn = min(mn, spar[0][i]);
        if (i > 1)
            logging[i] = logging[i/2]+1;
    }
    logging[n] = logging[n/2]+1;

    //build
    for (int i = 1; i < sz; ++i) {
        for (int j = 0; j <= n-(1 << i); ++j) {
            spar[i][j] = min(spar[i-1][j], spar[i-1][j+(1 << (i-1))]);
        }
    }

    ll mxx = LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        l = 0, r = i;
        p = logging[r-l+1];
        mxx = max(min(spar[p][l], spar[p][r-(1 << p)+1]), mxx);

        l = i, r = n-1;
        p = logging[r-l+1];
        mxx = max(min(spar[p][l], spar[p][r-(1 << p)+1]), mxx);
    }

    if (k == 1)
        cout << mn;
    else if (k > 2)
        cout << mx;
    else {
        if (mx == spar[0][0] || mx == spar[0][n-1])
            cout << mx;
        else {
            cout << mxx;
        }
    }
    cout << endl;

    return 0;
}