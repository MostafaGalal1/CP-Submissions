#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        string s;
        cin >> s;

        for_each(s.begin(), s.end(), [](char & c){
            c = ::tolower(c);
        });

        if (s == "yes" && s.length() == 3)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
    return 0;
}