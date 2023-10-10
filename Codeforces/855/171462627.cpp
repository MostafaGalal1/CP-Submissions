#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main()
{
    fast();

    ll t;
    string s;
    cin >> t;
    unordered_map<string, bool> memo;

    for (int i = 0; i < t; ++i) {
        cin >> s;
        if (memo[s])
            cout << "YES";
        else
            cout << "NO", memo[s] = true;
        cout << endl;
    }

    return 0;
}
