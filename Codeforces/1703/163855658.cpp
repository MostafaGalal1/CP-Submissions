#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        map <char, bool> mapp;
        int n, count = 0;
        string s;
        cin >> n;
        cin >> s;

        for (int i = 0; i < n; i++){
            if(!mapp[s[i]]) {
                mapp[s[i]] = true;
                count += 2;
            } else {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}