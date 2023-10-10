#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, a, b, p, q, num;
    cin >> n >> a >> b >> p >> q;
    num = n/a * p + n/b * q - n/((a * b) / __gcd(a, b)) * min(p, q);

    cout << num << endl;
}
