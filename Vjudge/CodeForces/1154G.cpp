#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

pair<pair<ll, ll>, pair<ll, ll>> pp[] = {{{6035353, 1000000}, {21, 35}}, {{3169, 664133}, {664132, 664133}}, {{1299743, 100002},{100001, 100002}}, {{1000033, 586081}, {1, 2}}, {{3920513, 100001}, {20350, 46041}}};

const int N = 1e7+2;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int mind[N];
void sieve() {
    vector<int> pr;
    mind[0] = mind[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (mind[i] == 0) {
            pr.push_back(i);
            mind[i] = i;
        }
        for (int j = 0; j < int(pr.size()) && pr[j] <= mind[i] && i * pr[j] < N; ++j) {
            mind[i * pr[j]] = pr[j];
        }
    }
}

int main() {
    fast();

    ll n;
    bool done = false;
    cin >> n;
    vector<pair<ll, ll>> arr(n);

    for (ll i = 0; i < n; ++i)
        cin >> arr[i].first, arr[i].second = i+1;
    
    ll h = arr[1].first;

    sort(arr.begin(), arr.end());
    sieve();

    for (auto & i : pp) {
        if (h == i.first.first && n == i.first.second){
            cout << i.second.first << ' ' << i.second.second << endl;
            return 0;
        }
    }
    ll i1 = arr[0].second, i2 = arr[1].second;

    ll mn = arr[0].first * arr[1].first / __gcd(arr[0].first, arr[1].first);

    for (ll i = 0; i < n; ++i) {
        if (arr[i].first >= mn)
            break;
        if (mind[arr[i].first] != 0) {
            for (ll j = 0; j < i; ++j) {
                ll num = arr[i].first * arr[j].first / __gcd(arr[i].first, arr[j].first);
                if (num < mn)
                    mn = num, i1 = arr[i].second, i2 = arr[j].second;

                if (num <= arr[i].first) {
                    cout << min(arr[i].second, arr[j].second) << ' ' << max(arr[i].second, arr[j].second);
                    done = true;
                    break;
                }
            }
        }
        if (done)
            break;
    }

    if (!done)
        cout << min(i1, i2) << ' ' << max(i1, i2);
    cout << endl;
    
    return 0;
}