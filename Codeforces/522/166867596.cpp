#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

map<string, ll> mapp;

vector<ll> arr[N];
bool visited[N];
ll num = 0, mx = 0;

void dfs(ll node){
    visited[node] = true;
    num++;
    for(ll child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
    mx = max(num, mx);
    num--;
}

int main() {
    ll n, i = 1;
    cin >> n;

    for (int j = 0; j <= n; ++j) {
        string s, t, u, v;
        getline(cin, s);
        stringstream x(s);

        while(getline(x,t,' ')){
            for_each(t.begin(), t.end(), [](char & c){
                c = ::tolower(c);
            });

            if (t != "reposted") {
                if (mapp[t]){
                    if (u.empty())
                        u = t;
                    else
                        v = t;
                } else {
                    if (u.empty()) {
                        u = t;
                        mapp[t] = i++;
                    } else {
                        v = t;
                        mapp[t] = i++;
                    }
                }
            }
        }

        if (!(u.empty() || v.empty())) {
            arr[mapp[u]].push_back(mapp[v]);
            arr[mapp[v]].push_back(mapp[u]);
        }
    }

    if (mapp["polycarp"])
        dfs(mapp["polycarp"]);

    cout << mx << endl;

    return 0;
}