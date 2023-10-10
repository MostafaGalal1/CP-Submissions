#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    bool done = false;

    for (int i = n; i <= m; ++i) {
        set<int> st;
        string s = to_string(i);
        for (char j : s) {
            st.insert(j - '0');
        }

        if (st.size() == s.length()) {
            cout << s << endl;
            done = true;
            break;
        }
    }

    if (!done)
        cout << -1 << endl;
    return 0;
}