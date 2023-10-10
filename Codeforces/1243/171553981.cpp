#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        map<pair<int, char>, ll> mapp;

        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]){
                mapp[{1, s1[i]}]++, mapp[{2, s2[i]}]++;
            }
        }

        if (mapp.empty() || mapp.size() == 2){
            bool done = false;
            for (auto & i : mapp) {
                if (i.second != 2) {
                    cout << "No";
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }

    return 0;
}
