#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    queue<int> s;

    while(t --> 0){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int op, n;
        cin >> op;

        if (op == 1) {
            cin >> n;
            s.push(n);
        } else if (op == 2) {
            if (!s.empty())
                s.pop();
        } else if (op == 3) {
            if (s.empty())
                cout << "Empty!\n";
            else
                cout << s.front() << "\n";
        }
    }
    return 0;
}