#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e6 + 10;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void sieve(int n, vector<bool> &prime){
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
}


int main() {
    fast();

    ll n, num;
    cin >> n;

    vector<bool> prime(N, true);
    sieve(N, prime);

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (abs(sqrt(num) - floor(sqrt(num))) < 1e-9 && prime[(int)sqrt(num)])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}