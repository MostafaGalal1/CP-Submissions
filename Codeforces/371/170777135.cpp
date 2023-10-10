#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll, bool> mapp;
bool prime = false;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

multiset<ll> primeFactors(ll n)
{
    multiset<ll> s;
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            if (!mapp[i])
                prime = true;
            n = n/i;
        }
    }
    if (n > 2) {
        s.insert(n);
        if (!mapp[n])
            prime = true;
    }

    return s;
}


int main() {
    fast();

    ll a, b;
    cin >> a >> b;

    mapp[2] = mapp[3] = mapp[5] = true;
    multiset<ll> s1, s2;
    s1 = primeFactors(a / __gcd(a,b));
    s2 = primeFactors(b / __gcd(a,b));

    if (!prime) {
        cout << abs((ll)s1.count(2) - (ll)s2.count(2)) + abs((ll)s1.count(3) - (ll)s2.count(3)) + abs((ll)s1.count(5) - (ll)s2.count(5));
    } else {
        cout << -1;
    }
    cout << endl;

    return 0;
}