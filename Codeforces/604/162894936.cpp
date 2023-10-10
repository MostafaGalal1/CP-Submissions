#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    string s;
    cin >> s;

    if (s.length() < 4){
        cout << s.length() << endl;
        return 0;
    }

    for (int i = 0; i < s.length()-1; i++) {
        if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0')){
            count++;
            if (count + 3 == s.length())
                break;
        }
    }

    cout << (count + 3) << endl;
    return 0;
}