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

        vector<ll> a(non), zby;
        ll control = 0;

        for (int i = 0; i < non; ++i) {
            cin >> a[i];
            ll tu = a[i];
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            ll answwe = 0;
            while (tu%2 == 0){
                answwe++;
                tu /= 2;
            }
            control += answwe;


            answwe = 0;

            ll ind = i+1;

            while (ind%2 == 0){
                answwe++;
                ind /= 2;
            }
            zby.push_back(answwe);
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }

        sort(zby.begin(), zby.end());
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        ll o = non-1, answwe = 0;
        while (control < non && o > 0){
            control += zby[o];
            answwe++;
            o--;
        }

        if (control < non) {
            cout << -1;
        } else
            cout << answwe;

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