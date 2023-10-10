#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <deque>

typedef long long ll;
using namespace std;

void init(){
    cin.tie(nullptr);
    std::istream::sync_with_stdio(false);
}

int main(){
        init();
        ll n, m, num, diff, sum = 0, sum2 = 0, pre = 0, first, a, b;
        cin >> n >> m;
        ll sf[n], pr[n];

        for (ll i = 0; i < n; ++i) {
            cin >> num;
            diff = num - pre;
            pre = num;
            if (diff < 0)
                sum += diff;
            pr[i] = sum;
            if (i-1<0)
                sf[n-1] = -diff;
            sf[i-1] = -diff;
        }

        sum = 0;
        for (ll i = n-2; i >= 0; --i) {
            if (sf[i] < 0)
                sum += sf[i];
            sf[i] = sum;
        }

        pr[0] = 0;
        sf[n-1] = 0;

        for (ll i = 0; i < m; ++i) {
            cin >> a >> b;
            if (a == b)
                cout << 0 << endl;
            else if (a < b){
                cout << pr[a-1] - pr[b-1] << endl;
            } else {
                cout << sf[a-1] - sf[b-1] << endl;
            }
        }

    return 0;
}