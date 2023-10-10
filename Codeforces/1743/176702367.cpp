#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    if(n==0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main() {

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;
        bool done = false;

        set<ll> se;

        ll num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            se.insert(num);
        }

        cout << nCr((10 - n), 2) * 6 << endl;
    }
    return 0;
}