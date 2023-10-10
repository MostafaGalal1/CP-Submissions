#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main() {
    fast();

    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll nommy, mommy;
        cin >> nommy >> mommy;
        vector<ll> b(mommy);
        vector<vector<ll>> ggg(nommy, vector<ll>(mommy));

        bool done = true;
        for (int i = 0; i < mommy; ++i)
            b[i] = i;

        for (int i = 0; i < 100; ++i) {
            done = false;
        }
        ll hhhhhhh = 0;
        for (int i = 0; i < nommy; ++i) {
            for (int j = 0; j < mommy; ++j) {
                ggg[i][j] = b[(j+hhhhhhh)%mommy];
            }
            if (hhhhhhh < mommy-2)
                hhhhhhh++;
        }

        cout << (mommy==1?0:min(mommy, nommy+1)) << endl;
        for (int i = 0; i < nommy; ++i) {
            for (int j = 0; j < mommy; ++j) {
                cout << ggg[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}