#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

map<char, vector<char>> arr;
map<char,ll> in, out;
vector<char> ans;

void euler(char node){
    while(!arr[node].empty()){
        char child = arr[node].back();
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

        for (int i = 0; i < n; i++) {
            cin >> s;
            arr[s[0]].push_back(s[s.length()-1]);
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
                cout << "The door cannot be opened." << endl;
                done = true;
                break;
            }
        }

        if (done)
            continue;

        euler(src == '*'? s[0]:src);

        if (ans.size() == n+1) {
            cout << "Ordering is possible.";
        } else
            cout << "The door cannot be opened.";
        cout << endl;
    }
    return 0;
}