#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n, num;
        cin >> n;
        vector<ll> arr(n);
        map<ll, ll> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            arr[i] = -num;
        }

        for (int i = 0; i < n; ++i) {
            cin >> num;
            arr[i] += num;
            mapp[arr[i]]++;
        }

        ll cnt = 0;

        while(!mapp.empty()) {
            if (mapp.begin()->first >= 0)
                break;
            auto it = mapp.lower_bound(-mapp.begin()->first);
            if (it != mapp.end()) {
                cnt++;
                mapp[it->first]--;
                if (!mapp[it->first])
                    mapp.erase(it);
            }
            if (!mapp.empty()) {
                mapp[mapp.begin()->first]--;
                if (!mapp[mapp.begin()->first])
                    mapp.erase(mapp.begin());
            }
        }

        ll res = 0;
        for(auto & i : mapp) {
            res += i.second;
        }
        cout << cnt + res/2 << endl;
    }

    return 0;
}
