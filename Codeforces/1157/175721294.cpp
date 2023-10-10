#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+10;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool start = true;

    vector<char> a(10);
    for (int i = 1; i < 10; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[s[i]-'0'] > s[i])
            s[i] = a[s[i]-'0'], start = false;
        else if (!start && a[s[i]-'0'] < s[i])
            break;
    }

    cout << s << endl;

    return 0;
}