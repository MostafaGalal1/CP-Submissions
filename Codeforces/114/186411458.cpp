#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<string> sub(vector<string> arr, ll n, map<string, set<string>> &mapp)
{
    ll mx = 0;
    vector<string> res;
    ll count = (ll)pow(2, n);
    for (int i = 0; i < count; i++) {
        vector<string> sus;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0)
                sus.push_back(arr[j]);
        }
        bool done = false;
        for (int j = 0; j < sus.size() && !done; ++j) {
            for (int k = j; k < sus.size(); ++k) {
                if (mapp[sus[j]].find(sus[k]) != mapp[sus[j]].end()){
                    done = true;
                    break;
                }
            }
        }
        if (!done){
            if (mx < (ll)sus.size()){
                mx = (ll)sus.size();
                res = sus;
            }
        }
    }
    return res;
}

int main()
{
    fast();
    ll t = 1;

    while (t --> 0) {
        ll k, n;
        bool done = false;
        cin >> n >> k;
        map<string, set<string>> mapp;
        vector<string> ss;

        string s, p;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            ss.push_back(s);
            mapp[s];
        }

        for (int i = 0; i < k; ++i) {
            cin >> s >> p;
            mapp[s].insert(p);
            mapp[p].insert(s);
        }
        vector<string> lol = sub(ss, n, mapp);
        sort(lol.begin(), lol.end());

        cout << (ll)lol.size() << endl;
        for (int i = 0; i < (ll)lol.size(); ++i) {
            cout << lol[i] << endl;
        }
    }
    return 0;
}