#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        string s;
        ll cnt = 0;
        cin >> s;
        string s1, one = "one";
        string s2, two = "two";
        set<ll> se1, se2;

        ll ind1 = 0, ind2 = 0;
        while ((ind1 = s.find(one, ind1)) != std::string::npos) {
            se1.insert(ind1+1);
            ind1 += one.length();
        }

        while ((ind2 = s.find(two, ind2)) != std::string::npos) {
            se2.insert(ind2+1);
            ind2 += one.length();
        }

        vector<ll> v;
        cnt = se1.size();
        for (ll ss : se1){
            auto it = se2.lower_bound(ss - 2);
            if (*it == ss - 2) {
                se2.erase(ss - 2);
                v.push_back(ss);
            }
        }

        for (int i = 0; i < v.size(); ++i) {
            se1.erase(v[i]);
            se1.insert(v[i]-1);
        }

        cnt += se2.size();
        cout << cnt << endl;
        for (ll ss : se1) {
            cout << ss+1 << ' ';
        }
        for (ll ss : se2) {
            cout << ss+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}