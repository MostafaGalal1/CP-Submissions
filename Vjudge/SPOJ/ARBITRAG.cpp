#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll oo = INT_MAX;
const ll N = 510;

map<string, ll> mapp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, t = 1;
    cin >> n;

    while (n) {
        bool cycle = false;
        ld arr[n][n];
        string s, ss;
        string str[3];

        for (int i = 0; i < n; ++i) {
            cin >> s;
            mapp[s] = i;
            for (int j = 0; j < n; ++j) {
                arr[i][j] = oo;
            }
        }

        cin >> m;
        cin.ignore();

        for (int i = 0; i < m; ++i) {
            getline(cin, s);

            int j = 0;
            stringstream ssin(s);
            while (ssin.good() && j < 3){
                ssin >> str[j];
                j++;
            }
            arr[mapp[str[0]]][mapp[str[2]]] = 1 / stod(str[1]);
        }


        for (ll k = 0; k < n; ++k) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (arr[i][j] > abs(arr[i][k] * arr[k][j]))
                        arr[i][j] = abs(arr[i][k] * arr[k][j]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (arr[i][i] < 1) {
                cycle = true;
                break;
            }
        }

        if (cycle)
            cout << "Case " << t << ": Yes";
        else
            cout << "Case " << t << ": No";

        t++;
        cout << endl;
        cin >> n;
    }
    return 0;;
}