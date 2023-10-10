#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        bool done = false;
        int n, k;
        string s;
        cin >> n >> k >> s;

        if (k == 0)
            cout << 1;
        else {
            for (int i = 0; i < s.length()/2; i++) {
                if (s[i] != s[s.length() - 1 - i]){
                    cout << 2;
                    done = true;
                    break;
                }
            }
            if (!done)
                cout << 1;
        }
        cout << endl;
    }

    return 0;
}