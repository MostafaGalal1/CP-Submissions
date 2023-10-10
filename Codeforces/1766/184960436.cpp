#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n;
        cin >> n;
        string s;
        vector<vector<int>> g(2, vector<int>(n, 0));
        cin >> s;


        char ch;
        for (int i = 0; i < n; ++i) {
            ch = s[i];
            if (ch == 'B'){
                g[0][i] = 1;
            } else {
                g[0][i] = 0;
            }
        }

        cin >> s;

        for (int i = 0; i < n; ++i) {
            ch = s[i];
            if (ch == 'B'){
                g[1][i] = 1;
            } else {
                g[1][i] = 0;
            }
        }

        ll cnt = 0;

        bool done = false;
        ll ind = 2;

        for (int i = 0; i < n-1 && !done; ++i) {
            if (!(g[0][i] & g[0][i+1]) && !(g[1][i] & g[1][i+1])){
                cout << "NO";
                done = true;
                break;
            } else if ((g[0][i] & g[0][i+1]) && !(g[1][i] & g[1][i+1])){
                if ((cnt%2 == 0 && ind == 0) || (cnt%2 == 1 && ind == 1) || ind == 2)
                    ind = 0, cnt = 0;
                else {
                    cout << "NO";
                    done = true;
                    break;
                }
            } else if (!(g[0][i] & g[0][i+1]) && (g[1][i] & g[1][i+1])) {
                if ((cnt%2 == 0 && ind == 1) || (cnt%2 == 1 && ind == 0) || ind == 2)
                    ind = 1, cnt = 0;
                else {
                    cout << "NO";
                    done = true;
                    break;
                }
            }

            if (g[0][i+1] == 1 && g[1][i+1] == 1)
                cnt++;
        }

        if (!done){
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}