#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll n;
    cin >> n;
    vector<ll> s;

    for (int i = 2; i <= (ll)sqrt(n); ++i) {
        if (n%i == 0)
            s.push_back(i), s.push_back(n/i);
    }
    s.push_back(n);

    sort(s.begin(), s.end());
    ll cnt = s[0];

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            if (s[j]%s[i]){
                cnt = 1;
                break;
            }
        }
        if (cnt == 1)
            break;
    }

    cout << cnt << endl;

    return 0;
}
