#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<ll> divs;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void divisors(ll n)
{
    divs.clear();
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) {
            if (n/i == i)
                divs.push_back(i);
            else {
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
}

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr.begin(), arr.end());

        ll res = arr[0] * arr[n-1];
        divisors(res);

        sort(divs.begin(), divs.end());

        if (arr == divs){
            cout << res;
        } else
            cout << -1;

        cout << endl;
    }

    return 0;
}