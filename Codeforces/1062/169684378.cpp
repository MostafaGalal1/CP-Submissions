#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
unordered_map<ll, ll> mapp;

void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        mapp[2]++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mapp[i]++;
            n = n/i;
        }
    }

    if (n > 2)
        mapp[n]++;
}

int main() {
    fast();

    ll n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << ' ' << 0 << endl;
        return 0;
    }

    primeFactors(n);

    ll mx = 0, res = 1;
    bool done = false;
    for (auto & i : mapp){
        res *= i.first;
        if (i.second != mx && mx) {
            mx = max(mx, i.second);
            done = true;
        } else if (!mx)
            mx = i.second;
    }

    cout << res << ' ' << (ll)ceil(log2(mx)) + (done || log2(mx) != floor(log2(mx))?1ll:0ll) << endl;

    return 0;
}