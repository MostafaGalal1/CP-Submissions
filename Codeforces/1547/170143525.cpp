#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        pair<ll, ll> a, b, f;
        cin >> a.first >> a.second >> b.first >> b.second >> f.first >> f.second;

        if ((a.first == b.first && a.first == f.first && ((f.second < a.second && f.second > b.second) || (f.second > a.second && f.second < b.second))) || (a.second == b.second && a.second == f.second) && ((f.first < a.first && f.first > b.first) || (f.first > a.first && f.first < b.first)))
            cout << abs(a.first - b.first) + abs(a.second - b.second) + 2;
        else
            cout << abs(a.first - b.first) + abs(a.second - b.second);
        cout << endl;
    }

    return 0;
}