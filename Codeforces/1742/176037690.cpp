#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node{
    node *nxt[26]{};
    node(){memset(nxt, 0, sizeof(nxt));}
} *root;

void insert(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            cur->nxt[i - 'a'] = new node();
        cur = cur->nxt[i - 'a'];
    }
}

void pppt(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            cur->nxt[i - 'a'] = new node();
        cur = cur->nxt[i - 'a'];
    }
}

bool visited[1];

void dfs(ll node){
    stack<ll> st;
    visited[node] = true;
    st.push(node);

}


int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<ll> attt(n), bbbb(n);
        vector<bool> bo(n);

        for (int i = 0; i < n; ++i) {
            cin >> attt[i];
            bbbb[i] = attt[i];
        }

        bool fg = 0;
        for (int i = 0; i < 1; ++i) {
            fg = 1;
        }

        while (true){
            ll mx = 0;
            ll ind;
            for (int i = 0; i < n; ++i) {
                if (mx < bbbb[i]){
                    mx = max(mx, bbbb[i]);
                    ind = i;
                }
            }
            if (bbbb[ind] == 0){
                break;
            }
            cout << attt[ind] << ' ';
            bo[ind] = true;
            for (int i = 0; i < n; ++i) {
                bbbb[i] &= (~attt[ind]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bo[i])
                cout << attt[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}