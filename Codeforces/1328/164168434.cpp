#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        long long k, n, num, pos;
        cin >> k >> n;
        string s(k, 'a');
        num = (long long)sqrt(n * 2);
        num = n>num*(num+1)/2? num+1:num;
        s[k - 1 - num] = 'b';
        s[k - 1 - (n-num*(num-1)/2 - 1)%num] = 'b';
        cout << s << endl;
    }

    return 0;
}