#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

string decToBinary(ll n)
{
    string r, t;

    ll i = 0;
    while (n > 0) {
        t = ((n % 2) + '0');
        r = t + r;
        n = n / 2;
        i++;
    }

    return r;
}


int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, l;
        ll nu, ans = 0;
        string num, res;

        cin >> n >> l;

        ll zeros[l], ones[l];
        memset(zeros, 0, sizeof(zeros));
        memset(ones, 0, sizeof(ones));

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            num = decToBinary(nu);
            string rem(l - num.length(), '0');
            num = rem + num;
            for (int j = 0; j < l; ++j) {
                if (num[j] == '0')
                    zeros[j]++;
                else
                    ones[j]++;
            }
        }

        for (int i = 0; i < l; ++i) {
            res += (zeros[i] >= ones[i]? '0':'1');
        }

        for (int i = 0; i < l; ++i) {
            ans += (res[i] - '0');
            ans <<= 1;
        }
        ans >>= 1;

        cout << ans << endl;
    }

    return 0;
}