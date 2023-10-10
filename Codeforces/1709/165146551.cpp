#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <deque>

typedef long long ll;
using namespace std;

void init(){
    cin.tie(nullptr);
    std::istream::sync_with_stdio(false);
}

int main(){
    init();

    ll t;
    cin >> t;

    while(t --> 0){
        init();
        int x, a ,b ,c;
        cin >> x >> a >> b >> c;

        if (x==1 && a != 0) {
            if ((a == 2 && b != 0) || (a == 3 && c != 0))
                cout << "YES";
            else
                cout << "NO";
        }else if (x == 2 && b != 0) {
            if ((b == 1 && a != 0) || (b == 3 && c != 0))
                cout << "YES";
            else
                cout << "NO";
        }else if (x == 3 && c != 0) {
            if ((c == 1 && a != 0) || (c == 2 && b != 0))
                cout << "YES";
            else
                cout << "NO";
        }else {
                cout << "NO";
        }
        cout << endl;
    }

    return 0;
}