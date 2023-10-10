#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

map<ll, ll> primeFactors(ll n)
{
    map<ll, ll> mapp;
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

    return mapp;
}

bool check(map<ll, ll> m){
    if (m.size() > 2)
        return false;
    if (m.size() == 2 && (m[2] == 0 || m[3] == 0))
        return false;
    m.erase(2), m.erase(3);
    if (m.size() == 1 && (m[2] == 0 && m[3] == 0))
        return false;
    return true;
}

int main()
{
    fast();

    double n, m;
    cin >> n >> m;
    double mx = max(n, m), mn = min(n, m);
    ll gcd = __gcd((ll)n, (ll)m);

    if (mx/mn - floor(mx/mn) > 1e-9)
        cout << -1;
    else {
        map<ll, ll> m1, m2;
        m1 = primeFactors((ll)n/(ll)gcd);
        m2 = primeFactors((ll)m/(ll)gcd);

        if (check(m1) && check(m2)) {
            cout << abs(m1[2] - m2[2]) + abs(m1[3] - m2[3]);
        } else
            cout << -1;
    }

    cout << endl;

    return 0;
}
