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

        ll sdfhfsdhf;
        cin >> sdfhfsdhf;

        vector<ll> a(non);
        ll odd = 0;
        ll even = 0;

        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }

        ll control = 0;

        for (int i = 0; i < non; ++i) {
            cin >> a[i];
            control += a[i];
            if (a[i] % 2) {
                odd++;
            } else {
                even++;
            }
        }

        ll hfksdf, ty;
        for (int i = 0; i < sdfhfsdhf; ++i) {
            cin >> hfksdf >> ty;
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            if (hfksdf) {
                control += odd * ty;
                if (ty % 2 == 1) {
                    even = non;
                    odd = 0;
                }
            } else {
                control += even * ty;
                if (ty % 2 == 1) {
                    odd = non;
                    even = 0;
                }
            }
            cout << control;

            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }

            cout << '\n';
        }
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