#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        string s;
        cin >> n >> s;

        stack<char> st, sb;
        vector<int> res(n, 0);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '('){
                if (sb.empty()) {
                    st.push('(');
                    res[i] = 1;
                } else {
                    sb.pop();
                    res[i] = 2;
                }
            } else {
                if (st.empty()) {
                    sb.push(')');
                    res[i] = 2;
                } else {
                    st.pop();
                    res[i] = 1;
                }
            }
        }

        if (st.empty() && sb.empty()) {
            bool d = true;
            for (int i = 0; i < n-1; ++i) {
                if (res[i] != res[i+1]){
                    d = false;
                    break;
                }
            }

            cout << (d?1:2) << endl;
            for (int i = 0; i < n; ++i) {
                cout << (d?1:res[i]) << ' ';
            }
        } else
            cout << -1;
        cout << endl;
    }

    return 0;
}
