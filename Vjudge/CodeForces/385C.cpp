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
    vector<int> count(N);

    for (int i = 0; i < n; ++i) {
        cin >> num;
        count[num]++;
    }

    vector<bool> prime(N, true);

    sieve(N, prime);

    vector<ll> pre(N, 0);

    for (int i = 0; i < N; ++i) {
        if (prime[i]) {
            for (int j = i; j < N; j += i) {
                pre[i] += count[j];
            }
        }
    }

    for (int i = 1; i < N; ++i)
        pre[i] += pre[i - 1];

    cin >> q;

    while (q --> 0){
        cin >> l >> r;
        cout <<  pre[max(min(r, N - 1), 0)] - pre[min(max(l - 1,0), N-1)] << endl;
    }
}
