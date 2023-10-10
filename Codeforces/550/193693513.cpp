#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    bool done = false;
    string s, strnum;
    cin >> s;
    ll n = (ll)s.length(), num;

    if (s.find('0') != string::npos){
        strnum = '0';
        done = true;
    } else if (s.find('8') !=string::npos){
        strnum = '8';
        done = true;
    }

    for (int i = 0; i < n && !done; ++i) {
        for (int j = i + 1; j < n; ++j) {
            strnum = "";
            strnum += s[i];
            strnum += s[j];
            num = stoll(strnum);
            if (num%8 == 0){
                done = true;
                break;
            }
        }
    }

    for (int i = 0; i < n && !done; ++i) {
        for (int j = i+1; j < n && !done; ++j) {
            for (int k = j+1; k < n; ++k) {
                strnum = "";
                strnum += s[i];
                strnum += s[j];
                strnum += s[k];
                num = stoll(strnum);
                if (num%8 == 0){
                    done = true;
                    break;
                }
            }
        }
    }

    if (done) {
        cout << "YES" << endl;
        cout << strnum;
    } else
        cout << "NO";
    cout << endl;

    return 0;
}