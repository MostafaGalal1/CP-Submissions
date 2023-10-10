#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll cnt = 0;

void print(ll n, ll k){
    if (cnt >= k) {
        cout << n << ' ';
        return;
    }

    if (n == 1) {
        cout << 1 << ' ';
        return;
    }

    cnt++;
    print(n/2, k);
    print(n/2, k);
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll nu = n;
    ll nt = 0;

    vector<ll> v;
    while (nu){
        v.push_back((ll)pow(2, (ll)log2(nu)));
        nu -= v[v.size()-1];
        nt++;
    }

    sort(v.begin(), v.end());
    cnt = (ll)v.size();

    if (k < nt || k > n)
        cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < (ll)v.size(); ++i) {
            print(v[i], k);
        }
    }
    cout << endl;

    return 0;
}