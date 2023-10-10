#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll n, m, k, sx, sy, ex, ey;
    cin >> n >> m >> k;
    ll lim = __gcd(m, n);
    ll sec1 = n/lim, sec2 = m/lim;

    for (int i = 0; i < k; ++i) {
        cin >> sx >> sy >> ex >> ey;
        if (sx == ex) {
            if ((sx == 1 && (sy-1)/sec1 == (ey-1)/sec1) || (sx == 2 && (sy-1)/sec2 == (ey-1)/sec2))
                cout << "YES";
            else
                cout << "NO";
        } else {
            if ((sx == 1 && (sy-1)/sec1 == (ey-1)/sec2) || (sx == 2 && (sy-1)/sec2 == (ey-1)/sec1))
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }

    return 0;
}
