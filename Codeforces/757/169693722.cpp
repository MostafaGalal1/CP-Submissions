#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
map<ll, ll> mapp;

void primeFactors(ll n)
{
    map<ll, bool> memo;
    while (n % 2 == 0)
    {
        if (!memo[2])
            mapp[2]++, memo[2] = true;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if (!memo[i])
                mapp[i]++, memo[i] = true;
            n = n/i;
        }
    }

    if (n > 2) {
        if (!memo[n])
            mapp[n]++, memo[n] = true;
    }
}

int main() {
    fast();

    ll n, num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        primeFactors(num);
    }

    ll mx = 1;
    for (auto &i : mapp)
        mx = max(mx, i.second);

    cout << mx << endl;

    return 0;
}