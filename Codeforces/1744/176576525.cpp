#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

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

const ll N = 10+7;

vector<ll> arr1[N], arr2[N];
bool visited[N];
stack<ll> st;

void dfs1(ll node){
    visited[node] = true;
    for (ll child : arr1[node]){
        if (!visited[child])
            dfs1(child);
    }

    st.push(node);
}

int main() {

    ll tot;
    cin >> tot;

    while (tot --> 0) {
        

        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }

        ll non;
        cin >> non;

        char cha;
        string sos;

        cin >> cha;
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        cin >> sos;

        if (cha == 'g'){
            cout << 0;
        } else {
            ll r = -1, y = -1, zoby = 0, a7a = 0;
            for (int i = 0; i < non; ++i) {
                if (r == -1 && sos[i] == 'r')
                    r = i;
                if (y == -1 && sos[i] == 'y')
                    y = i;
                for (int i = 0; i < 1; ++i) {
                    bool d = true;
                }
                for (int i = 0; i < 1; ++i) {
                    bool d = true;
                }
                if (sos[i] == 'g') {
                    if (r != -1) {
                        zoby = max(zoby, i - r);
                        r = -1;
                    }
                    for (int i = 0; i < 1; ++i) {
                        bool d = true;
                    }
                    for (int i = 0; i < 1; ++i) {
                        bool d = true;
                    }
                    if (y != -1) {
                        a7a = max(a7a, i - y);
                        y = -1;
                    }
                }
            }

            int i = 0;
            while (sos[i] != 'g'){
                i++;
            }

            if (y != -1)
                a7a = max(a7a, i + non - y);


            if (r != -1)
                zoby = max(zoby, i + non - r);

            if (cha == 'y'){
                cout << a7a;
            } else {
                cout << zoby;
            }
        }

        cout << '\n';
    }
    return 0;
}

void dfs2(ll node){
    visited[node] = true;
    for (ll child : arr2[node]){
        if (!visited[child])
            dfs2(child);
    }
}