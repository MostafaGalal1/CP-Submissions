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
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }

        bool b2olk = false;
        map<ll, char> zzobbrryyy;
        
        string yu;


        vector<ll> ver(non);
        for (int i = 0; i < non; ++i)
            cin >> ver[i];


        cin >> yu;


        for (int i = 0; i < non; ++i) {
            if (!zzobbrryyy[ver[i]]){
                zzobbrryyy[ver[i]] = yu[i];
                for (int i = 0; i < 1; ++i) {
                    bool d = true;
                }
                for (int i = 0; i < 1; ++i) {
                    bool d = true;
                }
            } else {
                if (zzobbrryyy[ver[i]] != yu[i]) {
                    b2olk = true;
                    break;
                }
            }
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
            for (int i = 0; i < 1; ++i) {
                bool d = true;
            }
        }

        if (!b2olk) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
        }
        for (int i = 0; i < 1; ++i) {
            bool d = true;
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