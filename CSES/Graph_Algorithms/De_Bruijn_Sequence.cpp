#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

stack<ll> st;
vector<bool> sb(1<<15, false);

bool dfs(ll node, ll n, vector<vector<ll>>& a){
    sb[node] = true;
    st.push(node);
    if ((ll)st.size() == (1<<n))
        return true;
    for (ll ch : a[node]){
        if (!sb[ch] && dfs(ch, n, a))
            return true;
    }
    st.pop();
    sb[node] = false;
    return false;
}

int main() {
    fast();
    ll n;
    cin >> n;

    vector<vector<ll>> a(1<<n);
    for (int i = 0; i < (1<<n); ++i) {
        if (i)
            a[i].push_back((i<<1)&((1<<n)-1));
        if (i != (1<<n)-1)
            a[i].push_back(((i<<1)|1)&((1<<n)-1));
    }

    dfs(0, n, a);

    string r;
    while (!st.empty()){
        r += (st.top()&1) + '0';
        st.pop();
    }
    r += string(n-1, '0');
    cout << r << endl;
    return 0;
}