#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool check = true;
    cin >> n;

    while(n --> 0){
        long long a;
        cin >> a;

        if(a%2 == 0)
            check = !check;

        if(check)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}