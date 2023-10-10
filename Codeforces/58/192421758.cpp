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

    vector<bool> v(5, false);
    for (int i = 0; i < s.length(); ++i) {
        if (v[0]){
            if (v[1]){
                if (v[2]){
                    if (v[3]){
                        if (s[i] == 'o') {
                            v[4] = true;
                            break;
                        }
                    } else {
                        if (s[i] == 'l')
                            v[3] = true;
                    }
                } else {
                    if (s[i] == 'l')
                        v[2] = true;
                }
            } else {
                if (s[i] == 'e')
                    v[1] = true;
            }
        } else {
            if (s[i] == 'h')
                v[0] = true;
        }
    }

    if (v[4])
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}