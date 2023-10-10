#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        bool done = false;
        string s;
        cin >> s;
        n = (ll)s.length();
        map<char, char> mapp, memo;

        for (int i = 0; i < n-1; ++i) {
            if ((!mapp[s[i]] && !memo[s[i + 1]])){
                mapp[s[i]] = s[i + 1];
                memo[s[i+1]] = s[i];
            } else if (mapp[s[i]] && mapp[s[i]] != s[i+1]){
                cout << "NO";
                done = true;
                break;
            } else if (memo[s[i+1]] && memo[s[i+1]] != s[i]){
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";

        cout << endl;
    }
    return 0;
}
