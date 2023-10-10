#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
map<char, bool> mapp;
int main()
{
    fast();
    string cod = "codeforces";
    for (int i = 0; i < cod.length(); ++i) {
        mapp[cod[i]] = true;
    }

    ll t;
    cin >> t;

    while (t --> 0) {
        char ch;
        bool done = false;
        cin >> ch;

        if (mapp[ch])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}