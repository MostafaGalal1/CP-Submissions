#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n, sz, q, l, r, p, cnt = 0;
    cin >> n >> q;

    sz = (ll)log2(n)+1;
    ll spar[sz][n], logging[n+1];
    memset(spar, 0, sizeof(spar));

    logging[0] = logging[1] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> spar[0][i];
        if (i > 1)
            logging[i] = logging[i/2]+1;
    }
    logging[n] = logging[n/2]+1;

    //build
    for (int i = 1; i < sz; ++i) {
        for (int j = 0; j <= n-(1 << i); ++j) {
            spar[i][j] = max(spar[i-1][j], spar[i-1][j+(1 << (i-1))]);
        }
    }

    //query overlap agnostic
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        l--, r-=2;
        p = logging[r-l+1];
        cnt += (max(spar[p][l], spar[p][r-(1 << p)+1]) == spar[0][l]? 1:0);
    }

    cout << cnt;;

    return 0;
}