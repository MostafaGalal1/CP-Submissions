#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        int r, b, g, w;
        cin >> r >> b >> g >> w;

        if (r == 0 || b == 0 || g == 0){
            if (r%2 == 0 && b%2 == 0 && g%2 == 0 && w%2 == 0)
                cout << "YES";
            else if (r%2 == 0 && b%2 == 0 && g%2 == 0 && w%2 == 1)
                cout << "YES";
            else if (r%2 == 0 && b%2 == 0 && g%2 == 1 && w%2 == 0)
                cout << "YES";
            else if (r%2 == 0 && b%2 == 1 && g%2 == 0 && w%2 == 0)
                cout << "YES";
            else if (r%2 == 1 && b%2 == 0 && g%2 == 0 && w%2 == 0)
                cout << "YES";
            else
                cout << "NO";
        } else {
            if (r%2 == 0 && b%2 == 0 && g%2 == 1 && w%2 == 1)
                cout << "No";
            else if (r%2 == 0 && b%2 == 1 && g%2 == 0 && w%2 == 1)
                cout << "No";
            else if (r%2 == 1 && b%2 == 0 && g%2 == 0 && w%2 == 1)
                cout << "No";
            else if (r%2 == 0 && b%2 == 1 && g%2 == 1 && w%2 == 0)
                cout << "No";
            else if (r%2 == 1 && b%2 == 0 && g%2 == 1 && w%2 == 0)
                cout << "No";
            else if (r%2 == 1 && b%2 == 1 && g%2 == 0 && w%2 == 0)
                cout << "No";
            else
                cout << "YES";
        }
        cout << endl;
    }

    return 0;
}