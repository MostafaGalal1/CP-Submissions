#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++){
        bool done = false;
        int a = 0;
        int b = 0;
        cin >> a;
        cin >> b;


        if (a == 0 || b == 0){
            cout << 0;
        } else {
            if (max(a, b) / min(a, b) < 3)
                cout << (a+b)/4;
            else
                cout << min(a, b);
        }
        cout << endl;
    }
    return 0;
}
