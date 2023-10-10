#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

int main() {
    ll n;
    cin >> n;

    deque<ll> q;

    if (n < 5){
        if (n == 1)
            cout << 1;
        else if (n == 4)
            cout << "2 4 1 3";
        else
            cout << "NO SOLUTION";
    } else {
        q = {4, 2, 5, 3 ,1};
        for (ll i = n; i > 5; --i) {
            if (i%2)
                q.push_back(i);
            else
                q.push_front(i);
        }

        ll sz = (ll)q.size();
        for (int i = 0; i < sz; ++i) {
            cout << q.front() << ' ';
            q.pop_front();
        }
    }

    cout << endl;

    return 0;
}