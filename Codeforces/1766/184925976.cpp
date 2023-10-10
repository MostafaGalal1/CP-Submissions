#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){

    ll t;
    cin >> t;

    while (t--> 0) {
        ll n;
        string s;
        bool done = false;
        cin >> n >> s;
        map<string, int> mapp;

        string prev;
        int ind;
        for (int i = 0; i < n-1; ++i) {
            string sd;
            sd += s[i];
            sd += s[i+1];
            if (sd != prev || (sd == prev && ind != i)) {
                mapp[sd]++;
                if (mapp[sd] > 1){
                    done = true;
                    cout << "YES";
                    break;
                }
                prev = sd;
                ind = i+1;
            }
        }

        if (!done)
            cout << "NO";
        cout << endl;
    }
}