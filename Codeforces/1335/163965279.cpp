#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        int n, a, b;
        string res;
        cin >> n >> a >> b;

        for (int i = 0 ; i < n ; i++){
            res += i%b + 97;
        }

        cout << res << endl;
    }
    return 0;
}