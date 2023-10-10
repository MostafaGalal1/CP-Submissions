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
        string s;
        cin >> s;
        map<char, vector<ll>> mapp;
        vector<char> v1, v2;

        mapp.clear();
        v1.clear(), v2.clear();

        for (int i = 0; i < s.length(); ++i) {
            mapp[s[i]].push_back(i);
        }

        ll cnt1 = 0, cnt2 = 0, cost1 = 0, cost2 = 0;
        int preval1 = s[0] - 'a', preval2 = s[0] - 'a';

        if (s[0] >= s[s.length() - 1]) {
            for (int i = preval1; i >= 0; --i) {
                if (!mapp['a' + i].empty()) {
                    cnt1 += mapp['a' + i].size();
                    v1.push_back('a' + i);
                    cost1 += abs(preval1 - i);
                    preval1 = i;
                }
                if (s[s.length() - 1] == i + 'a')
                    break;
            }
            cout << cost1 << ' ' << cnt1 << endl;
            for (int i = 0; i < v1.size(); ++i) {
                for (int j = 0; j < mapp[v1[i]].size(); ++j) {
                    cout << mapp[v1[i]][j] + 1 << ' ';
                }
            }
            cout << endl;
        } else {
                for (int i = preval2; i < 26; ++i) {
                    if (!mapp['a' + i].empty()) {
                        cnt2 += mapp['a' + i].size();
                        v2.push_back('a' + i);
                        cost2 += abs(preval2 - i);
                        preval2 = i;
                    }
                    if (s[s.length() - 1] == i + 'a')
                        break;
                }
            cout << cost2 << ' ' << cnt2 << endl;
            for (int i = 0; i < v2.size(); ++i) {
                for (int j = 0; j < mapp[v2[i]].size(); ++j) {
                    cout << mapp[v2[i]][j] + 1 << ' ';
                }
            }
            cout << endl;
        }
    }

    return 0;
}
