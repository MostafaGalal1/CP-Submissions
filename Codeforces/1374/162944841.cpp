#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int solve(int num){
    if (num == 1)
        return 0;
    if (num % 6 == 0)
        return solve(num / 6)+1;
    else if (num % 3 == 0)
        return solve(num * 2)+1;
    else
        return -INT_MAX;
}

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n;
        cin >> n;
        int res = solve(n);

        if (res < 0)
            cout << -1;
        else
            cout << res;
        cout << endl;
    }
}