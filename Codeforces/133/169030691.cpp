#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    bool done = false;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            cout << "YES";
            done = true;
            break;
        }
    }

    if (!done)
        cout << "NO";

    cout << endl;
    return  0;
}
