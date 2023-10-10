#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e7 + 1;

void sieve(int n, vector<bool> &prime){
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
}

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    int n, num, q, l ,r;
    cin >> n;

    vector<bool> prime(N, true);

    sieve(N, prime);
    ll i = 0, cnt = 0;
    while (cnt < n) {
        if (prime[i])
            cout << i << ' ', cnt++;
        i++;
    }
    cout << endl;

    return 0;
}