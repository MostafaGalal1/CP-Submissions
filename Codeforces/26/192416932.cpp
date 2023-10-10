#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    string s;
    cin >> s;
    stack<char> ss;
    ll res = s.length();

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(')
            ss.push('(');
        else if (s[i] == ')') {
            if (ss.empty())
                res--;
            else
                ss.pop();
        }
    }

    res -= ss.size();
    cout << res << endl;

    return 0;
}