#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
map<ll, ll> mapp;

ll cnt = 0;

void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        mapp[2]++;
        cnt++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mapp[i]++;
            cnt++;
            n = n/i;
        }
    }

    if (n > 2) {
        mapp[n]++;
        cnt++;
    }
}

int main() {
    fast();

    ll n, k, res = 1;
    cin >> n >> k;

    primeFactors(n);

    if (cnt < k) {
        cout << -1;
        return 0;
    } else {
        for (auto &i: mapp) {
            ll cur = i.second;
            if ((k-1) >= i.second){
                for (int j = 0; j < i.second; ++j)
                    cout << i.first << ' ';
                k -= i.second;
                continue;
            } else if (k != 1){
                for (int j = 0; j < k-1; ++j)
                    cout << i.first << ' ';
                cur = i.second - (k-1);
                k = 1;
            }

            if (k == 1) {
                res *= (ll) pow(i.first, cur);
            }
        }
    }

    cout << res << endl;

    return 0;
}