#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        string s;
        cin >> n >> s;
        ll a = 0, q = 0;
        vector<ll> va(n);
        vector<ll> vq(n);

        for (ll i = n-1; i >= 0; --i) {
            if (s[i] == 'Q')
                q++;
            else
                a++;
            va[i] = a;
            vq[i] = q;
        }

        bool done = false;
        for (ll i = n-1; i >= 0; --i) {
            if (vq[i] > va[i]){
                done = true;
                break;
            }
        }

        if (!done)
            cout << "Yes";
        else
            cout << "No";


        cout << endl;
    }
    return 0;
}