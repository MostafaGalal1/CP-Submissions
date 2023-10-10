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

    if (n == k){
        cout << -1 << endl;
        return 0;
    }
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if ((n%2 && k%2) || (n%2 == 0 && k%2 == 0)){
        cout << n << ' ';
    } else {
        cout << 1 << ' ';
    }

    ll kk = k;
    for (int i = 2; i < n; ++i) {
        if (k) {
            cout << i << ' ';
            k--;
        } else {
            cout << i+1 << ' ' << i << ' ';
            i++;
        }
    }

    if ((n%2 && kk%2) || (n%2 == 0 && kk%2 == 0)){
        cout << 1 << ' ';
    } else if (kk == n-1){
        cout << n << ' ';
    }

    return 0;
}