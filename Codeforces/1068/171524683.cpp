#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<ll> s;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void divisors(ll n) {
    for (ll i = 1; i <= (ll)sqrt(n); i++)
        if (n % i == 0)
            s.insert(i), s.insert(n/i);
}

int main()
{
    fast();

    ll n;
    cin >> n;

    divisors(n);
    cout << s.size() << endl;

    return 0;
}
