#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        int a, b;
        cin >> a >> b;
        int diff = abs(a-b);
        int fiv = diff/5;
        int two = (diff-fiv*5)/2;
        int one = diff-fiv*5-two*2;
        cout << fiv + two + one << endl;
    }
}