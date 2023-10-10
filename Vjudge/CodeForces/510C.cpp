#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 26;

string str;
map<ll, vector<ll>> arr;
bool visited[N], fin = false, cyclic = false;
bool onPath[N];
unordered_map<ll, bool> mapp;
vector<string> ve;

void dfs(ll node){
    if (cyclic)
        return;
    visited[node] = true;
    onPath[node] = true;
    for (ll child : arr[node]) {
        if (!visited[child])
            dfs(child);
        else if (onPath[child]){
            cyclic = true;
            return;
        }
    }

    str += node + 'a';

    onPath[node] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string s, ss;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        ve.push_back(s);
    }

    for (int i = 0; i < ve.size() - 1; i++){
        bool done = false;
        for (int j = 0; j < min(ve[i].length(), ve[i+1].length()); ++j){
            if (ve[i][j] != ve[i+1][j]){
                arr[ve[i][j] - 'a'].push_back(ve[i+1][j] - 'a');
                mapp[ve[i][j] - 'a'] = true, mapp[ve[i+1][j] - 'a'] = true;
                done = true;
                break;
            }
        }
        if (!done){
            if (ve[i].length() > ve[i+1].length()){
                cout << "Impossible" << endl;
                fin = true;
                break;
            }
        }
    }

    if (!fin) {
        for (auto &i : mapp) {
            if (cyclic)
                break;
            if (!visited[i.first] && !arr[i.first].empty()) {
                dfs(i.first);
                ss += str;
                str = "";
            }
        }

        if (cyclic)
            cout << "Impossible";
        else {
            char ch;
            for (int i = 0; i < 26; ++i) {
                if (!mapp[i]) {
                    ch = i + 'a';
                    cout << ch;;
                }
            }
            reverse(ss.begin(), ss.end());
            cout << ss;
        }
        cout << endl;
    }

    return 0;
}