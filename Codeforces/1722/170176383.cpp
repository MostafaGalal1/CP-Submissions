#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 4e5 + 10;

int main() {

    ll t;
    cin >> t;
    
    while (t --> 0) {
        map<char, int> mapp;
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (n!= 5)
            cout << "NO";
        else {
            for (int i = 0; i < s.length(); ++i)
                mapp[s[i]]++;

            if (mapp['T'] == 1 && mapp['r'] == 1 && mapp['u'] == 1 && mapp['m'] == 1 && mapp['i'] == 1)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }

    return 0;
}