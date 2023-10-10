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
        ll n, num;
        bool done = false;
        cin >> n;
        map<ll, vector<ll>> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            mapp[num].push_back(i);
        }

        for (auto & i : mapp) {
            if (i.second.size() > 2) {
                cout << "YES";
                done = true;
                break;
            } else if (i.second.size() == 2) {
                if (i.second[1] - i.second[0] > 1) {
                    cout << "YES";
                    done = true;
                    break;
                }
            }
        }

        if (!done)
            cout << "NO";
        cout << endl;
    }

    return 0;
}
