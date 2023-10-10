#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5+10;

ll cnt;
string s, r;
bool found = false;
map<string, bool> forb;
map<string, string> mapp;

void bfs(string node){
    queue<string> q;
    q.push(node);

    while (!q.empty()){
        string spr;
        node = q.front();
        q.pop();

        if (node == r) {
            found = true;
            return;
        }

        for(int i = 0; i < 4; i++){
            spr = node;
            spr[i] = ((node[i] - '0') + 1)%10 + '0';
            if (!forb[spr]) {
                forb[spr] = true;
                mapp[spr] = node;
                q.push(spr);
            }
            spr[i] = (node[i] == '0'? 9:(node[i] - '0') - 1)%10 + '0';
            if (!forb[spr]) {
                forb[spr] = true;
                mapp[spr] = node;
                q.push(spr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0) {
        string k;
        ll n, nm;

        cnt = 0;
        s = "", r = "";
        found = false;
        mapp.clear();
        forb.clear();

        for (int j = 0; j < 4; ++j) {
            cin >> nm;
            s += nm + '0';
        }
        for (int j = 0; j < 4; ++j) {
            cin >> nm;
            r += nm + '0';
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> nm;
                k += nm + '0';
            }
            forb[k] = true;
            k = "";
        }

        if (s == r)
            cout << 0;
        else {
            bfs(s);

            if (found) {
                while (mapp[r] != s) {
                    cnt++;
                    r = mapp[r];
                }
                cout << cnt + 1;
            } else
                cout << -1;
        }
        cout << endl;
    }
    return 0;;
}