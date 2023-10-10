#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> s;

int main(){
    ll t;
    cin >> t;

    for (int i = 0; i * i <= 2e5; ++i) {
        s.push_back(i * i);
    }

    while (t-->0){
        int n;
        cin >> n;
        stack<int> st;
        map<int, bool> mapp;

        n--;

        auto it = upper_bound(s.begin(), s.end(), 2*n);
        for (int i = n; i >= 0; --i) {
            if (*prev(it) - i > n)
                it = prev(it);
            while (mapp[*prev(it) - i])
                it = prev(it);
            st.push(*prev(it) - i);
            mapp[*prev(it) - i] = true;
        }

        while (!st.empty())
            cout << st.top() << ' ', st.pop();
        cout << endl;
    }

    return 0;
}