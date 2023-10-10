#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char arr[] = {'a','e','i','o','u', 'y'};

    for (int i = s.length() - 1; i >= 0; i--) {
        if (isalpha(s[i])){
            for (char j : arr) {
                if (tolower(s[i]) == j) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
            cout << "NO" << endl;
            return 0;
        }
    }
    return 0;
}