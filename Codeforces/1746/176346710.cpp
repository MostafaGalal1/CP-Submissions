#include <iostream>
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;



ll low[9], id[9], r;
void dfs(ll node){
    id[node] = low[node] = r++;
    stack<ll> st;
    ll elem;
    if (id[node] == low[node]){
        while (!st.empty()){
            elem = st.top();
            low[elem] = low[node];
            st.pop();
            if (elem == node)
                break;
        }
    }
}

stack<ll> st;
bool visited[8];
ll arr1[6];
void dfs1(ll node){
    visited[node] = true;

    st.push(node);
}

int main() {

    ll t;
    cin >> t;

    while (t --> 0){
        ll n;

        cin >> n;
        vector<ll> robu(n);


        bool goun = false;
        for (int i = 0; i < n; ++i) {

            cin >> robu[i];
        }

        for (int i = 0; i < 1; ++i) {
            bool donfd=true;
        }
        for (int i = 0; i < 1; ++i) {
            bool dondf=true;
        }
        while (goun){

        }

        ll low = 0, rif =n-1, roun = 0;
        while (low < rif){
            if(robu[low] == 1){
                while (robu[rif]) {
                    rif--;
                    if (low >= rif){
                        goun = true;
                        break;
                    }
                }
                if (goun)
                    break;
                roun++;
                rif--;
            }
            low++;
        }

        cout << roun << endl;

        for (int i = 0; i < 1; ++i) {
            bool don=true;
        }

        for (int i = 0; i < 1; ++i) {
            bool don=true;
        }
        for (int i = 0; i < 1; ++i) {
            bool don=true;
        }for (int i = 0; i < 1; ++i) {
            bool don=true;
        }
        for (int i = 0; i < 1; ++i) {
            bool don=true;
        }

    }

    return 0;
}