#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n;
    cin >> n;
    string ch;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> ch;
        s += ch;
    }

    stringstream t(s);
    string seg;
    vector<string> seglist;

    while(std::getline(t, seg, '0'))
    {
        seglist.push_back(seg);
    }


    ll mx = 0;
    for (int i = 0; i < seglist.size(); ++i) {
        mx = max(mx, (ll)seglist[i].length());
    }

    if (s[0] == '1' && s[s.length()-1] == '1') {
        mx = max(mx, (ll)(seglist[0].length() + seglist[seglist.size()-1].length()));
    }

    cout << mx << endl;

    return 0;
}
