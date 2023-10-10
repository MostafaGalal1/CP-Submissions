#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e7+5, inf = LONG_MAX, mod = 1e9+7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector <bool>prime(N,true);
vector<int>primes;
void Sieve()
{
//    primes.push_back(0);
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    for(int p=2;p<=N;p++){
        if(prime[p])
            primes.push_back(p);
    }
}

void func(ll p, ll q, vector<ll>& pl){
    ll mx = 0;
    for (ll i = 0; i <= 2e7; ++i) {
        auto it = prev(upper_bound(pl.begin(), pl.end(), i));
        auto it2 = prev(upper_bound(primes.begin(), primes.end(), i));
        if (q*(it2 - primes.begin() + 1) <= (it - pl.begin() + 1)*p){
            mx = max(mx, i);
        }
    }
    cout << mx << endl;
}

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0){
        ll p, q;
        cin >> p >> q;
        vector<ll> pl;

        Sieve();
        for (int number = 1; number <= 2e7; ++number) {
            if (isPalindrome(number)) {
                pl.push_back(number);
            }
        }

        func(p, q, pl);
    }
    return 0;
}