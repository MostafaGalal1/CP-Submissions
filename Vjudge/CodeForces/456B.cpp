#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    string n;
    cin >> n;
    
    if (n.length() == 1)
        n = '0' + n;

    if (((n[n.length()-1] == '0' || n[n.length()-1] == '4' || n[n.length()-1] == '8') && (n[n.length()-2] - '0')%2 == 0) || ((n[n.length()-1] == '2' || n[n.length()-1] == '6') && (n[n.length()-2] - '0')%2 == 1))
        cout << 4;
    else
        cout << 0;

    cout << endl;
    return 0;
}