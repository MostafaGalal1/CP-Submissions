#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact(ll n)
{
    if(n==0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main()
{
    double n, r;
    cin >> n >> r;

    double angle = 2/n * 3.14159265358979323846;
    double d = 2 / (1 - cos(angle));
    double a = 1 - d, b = 2 * r, c = r*r;
    cout << fixed << setprecision(14) << (-b - sqrt(b*b - 4*a*c))/(2*a) << endl;
}
