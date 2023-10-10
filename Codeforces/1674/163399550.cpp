#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n --> 0) {
        string s, t;
        cin >> s >> t;

        if (t.length() > 1 && t.find('a') != string::npos)
            cout << -1;
        else if(t.find('a') != string::npos)
            cout << 1;
        else
            cout << (long long)pow(2, s.length());
        cout << endl;
    }
    return 0;
}