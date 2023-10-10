#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll t, tt;
    cin >> t;
    tt = t;

    while (t-->0) {
        ll n;
        cin >> n;
        bool done = false;
        string s;
        cin >> s;

        int index = 0;
        while ((index = s.find("2020", index)) != std::string::npos) {
            if (index == 0 || index == n - 4) {
                done = true;
                break;
            }
            index += 2;
        }

        if (done || (s.substr(0, 2) == "20" && s.substr(n-2, 2) == "20") || (s[0] == '2' && s.substr(n-3,3) == "020") || (s[n-1] == '0' && s.substr(0,3) == "202"))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}