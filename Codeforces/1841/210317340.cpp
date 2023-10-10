#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

ll factorial(ll n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

ll ran(ll min, ll max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis((int)min, (int)max);

    return dis(gen);
}

// Function to calculate nCr (combination)
ll nCr(ll n, ll r) {
    ll numerator = factorial(n);
    ll denominator = factorial(r) * factorial(n - r);
    return numerator / denominator;
}

vector<vector<ll>> cc;
void gen(ll n, ll current_divisor, vector<ll> current_combination) {
    if (n == 1) {
        cc.push_back(current_combination);
        return;
    }

    for (ll divisor = current_divisor; divisor <= n; divisor++) {
        if (n % divisor == 0) {
            current_combination.push_back(divisor);
            gen(n / divisor, divisor, current_combination);
            current_combination.pop_back();
        }
    }
}

vector<ll> prime(ll n) {
    vector<ll> factors;

    // Check if 2 is a factor repeatedly
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for other prime factors starting from 3
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

vector<ll> generatePrimes(ll limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<ll> primes;

    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

long long getProductOfPrimes(ll limit) {
    vector<ll> primes = generatePrimes(limit);

    long long product = 1;
    for (ll prime : primes) {
        product *= prime;
    }

    return product;
}

unsigned long long fact(ll n) {
    unsigned long long result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> rem(n);
        for (int i = 0; i < n; ++i) {
            rem[i] = 1;
        }

        ll mn, mx = a[0];
        ll ind = n;
        for (int i = 1; i < n; ++i) {
            if (a[i] <= a[0] && a[i] < mx) {
                mn = a[i];
                ind = i;
                break;
            } else if (a[i] > a[0] && a[i] < mx){
                rem[i] = 0;
            } else {
                mx = a[i];
            }
        }

        for (int i = ind+1; i < n; ++i) {
            if (a[i] <= a[0] && a[i] >= mn) {
                mn = a[i];
            } else {
                rem[i] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << rem[i];
        }
        cout << endl;
    }

    return 0;
}