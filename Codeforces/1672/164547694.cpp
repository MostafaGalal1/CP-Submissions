#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
   long long t;
   cin >> t;

    while (t --> 0) {
        bool done = false;
        long long as = 0;
        string s;
        cin >> s;

        if (s.length() < 2 || s[s.length() - 1] == 'A') {
            cout << "NO";
        } else {
            for (char i : s) {
                if (i == 'A')
                    as++;
                else
                    as--;

                if (as < 0) {
                    cout << "NO";
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << "YES";
        }

        cout << endl;
    }
    return 0;
}