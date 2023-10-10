#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++){
        bool done = false;
        int n = 0;
        cin >> n;

        if (n%2 == 0){
            cout << 0;
        } else {
            string s = to_string(n);
            if ((int)s[0]%2 == 0)
                cout << 1;
            else{
                for (int j = 1; j < s.length()-1; j++){
                    if ((int)s[j]%2 == 0){
                        cout << 2;
                        done = true;
                        break;
                    }
                }
                if (!done)
                    cout << -1;
            }
        }
        cout << endl;
    }
    return 0;
}
