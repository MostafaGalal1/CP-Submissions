#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n1, n2;
        char ch;
        cin >> n1 >> n2;
        bool b1 = false, b2 = false;
        string s1, s2;
        cin >> s1 >> s2;
        bool done = false;

        for (int i = 0; i < n1-1; ++i) {
            if (s1[i] == s1[i+1]){
                if (!b1)
                    b1 = true;
                else {
                    done = true;
                    break;
                }
            }
        }

        if (b1){
            for (int i = 0; i < n2; ++i) {
                if (s2[n2-1] == s1[n1-1]){
                    done = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n2-1; ++i) {
            if (s2[i] == s2[i+1]){
                if (!b2)
                    b2 = true;
                else {
                    done = true;
                    break;
                }
                if (b1){
                    done = true;
                    break;
                }
            }
        }

        if (b2) {
            for (int i = 0; i < n2; ++i) {
                if (s2[n2 - 1] == s1[n1 - 1]) {
                    done = true;
                    break;
                }
            }
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";

        cout << endl;
    }

    return 0;
}