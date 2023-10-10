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
    int n, k, i1 = -2, i2 = -2, cnt = 0;
    cin >> n >> k;
    vector<bool> prime(n+1, true);

    sieve(n, prime);
    for (int i = 0; i <= n && i1 + i2 + 1 <= n; ++i) {
        if (prime[i]) {
            i2 = i;
            if (prime[i1 + i2 + 1]) {
                cnt++;
                if (cnt >= k)
                    break;
            }
            i1 = i2;
        }
    }
    cout << (cnt >= k? "YES":"NO") << endl;
}