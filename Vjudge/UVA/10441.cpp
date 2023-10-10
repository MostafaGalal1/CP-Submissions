#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

map<char, vector<pair<string ,char>>> arr;
map<char,ll> in, out;
vector<char> ans;
map<string, vector<string>> mapp;

void euler(char node){
    while(!arr[node].empty()){
        char child = arr[node].back().second;
        arr[node].pop_back();
        euler(child);
    }
    ans.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0) {
        bool done = false;
        ll n;
        char ch, src = '*', des = '*';
        cin >> n;
        string s;

        arr.clear(), ans.clear();
        in.clear(), out.clear();
        mapp.clear();

        char mn = 'z';

        for (int i = 0; i < n; i++) {
            cin >> s;
            mn = min(mn, s[0]);
            string ss;
            ss += s[0], ss += s[s.length()-1];
            mapp[ss].push_back(s);
            ll sum = 0;
            for (int j = 0; j < s.length(); ++j) {
                sum += s[j] - 'a';
            }
            arr[s[0]].emplace_back(s, s[s.length()-1]);
            out[s[0]]++, in[s[s.length()-1]]++;
        }

        for (int i = 0; i < 26; ++i) {
            ch = i + 'a';
            if (abs(in[ch] - out[ch]) == 1) {
                if (out[ch] == in[ch] + 1 && src == '*') {
                    src = ch;
                }
                else if (in[ch] == out[ch] + 1 && des == '*') {
                    des = ch;
                }
            } else if (abs(in[ch] - out[ch]) > 1) {
                cout << "***" << endl;
                done = true;
                break;
            }
        }

        if (done)
            continue;

        for (auto child : arr) {
            sort(child.second.rbegin(), child.second.rend());
            arr[child.first] = child.second;
        }

        for (auto child : mapp) {
            sort(child.second.rbegin(), child.second.rend());
            mapp[child.first] = child.second;
        }

        euler(src == '*'? mn:src);

        if (ans.size() == n+1) {
            for (int i = ans.size() - 1; i > 1; --i) {
                string ss;
                ss += ans[i], ss += ans[i-1];
                cout << mapp[ss].back() << '.';
                mapp[ss].pop_back();
            }
            string ss;
            ss += ans[1], ss += ans[0];
            cout << mapp[ss].back();
            mapp[ss].pop_back();
        } else
            cout << "***";
        cout << endl;;
    }
    return 0;
}