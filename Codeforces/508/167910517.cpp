#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

map<string, vector<string>> arr;
map<string, ll> in, out;
vector<string> ans;

void euler(string node){
    while(!arr[node].empty()){
        string child = arr[node].back();
        arr[node].pop_back();
        euler(child);
    }
    ans.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string s, s1, s2, ch, src = "*", des = "*";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        s1 = s.substr(0, 2);
        s2 = s.substr(1, 2);
        arr[s1].push_back(s2);
        out[s1]++, in[s2]++;
    }

    for (auto &child : arr) {
        ch = child.first;
        if (abs(in[ch] - out[ch]) == 1) {
            if (out[ch] == in[ch] + 1 && src == "*") {
                src = ch;
            }
            else if (in[ch] == out[ch] + 1 && des == "*") {
                des = ch;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (abs(in[ch] - out[ch]) > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    euler(src == "*"? ch:src);

    if (ans.size() == n+1) {
        cout << "YES" << endl;
        for (int i = n; i >= 0; --i) {
            cout << ans[i][0];
        }
        cout << ans[0][1];
    } else
        cout << "NO";
    cout << endl;
}