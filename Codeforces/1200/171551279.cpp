#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n, num;
    string s;

    cin >> n >> s;
    vector<bool> a(10, false);

    for (int j = 0; j < n; ++j) {
        if (s[j] == 'L') {
            for (int i = 0; i < 10; i++) {
                if (!a[i]) {
                    a[i] = true;
                    break;
                }
            }
        } else if (s[j] == 'R') {
            for (int i = 9; i >= 0; i--) {
                if (!a[i]) {
                    a[i] = true;
                    break;
                }
            }
        } else {
            num = s[j] - '0';
            a[num] = false;
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << (a[i]? '1':'0');
    }


    return 0;
}
