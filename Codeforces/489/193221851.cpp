#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n, m;

    cin >> n;
    vector<ll> nn(n);
    vector<multiset<ll>> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> nn[i];
    }

    cin >> m;
    vector<ll> mm(m);

    for (int i = 0; i < m; ++i) {
        cin >> mm[i];
    }

    sort(nn.begin(), nn.end());
    sort(mm.begin(), mm.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (abs(mm[j] - nn[i]) < 2)
                p[i].insert(j);
        }
    }

    sort(p.begin(), p.end());

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (!p[i].empty()) {
            res++;
            for (int j = i+1; j < n; ++j) {
                if (*p[j].lower_bound(*p[i].begin()) == *p[i].begin())
                    p[j].erase(p[j].lower_bound(*p[i].begin()));
            }
        }
    }

    cout << res << endl;
}
