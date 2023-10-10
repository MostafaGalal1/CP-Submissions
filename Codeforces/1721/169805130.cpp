#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {

    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        char a, b, c, d;
        cin >> a >> b >> c >> d;
        set<char> s;

        s.insert(a);
        s.insert(b);
        s.insert(c);
        s.insert(d);

        cout << s.size() - 1 << endl;
    }
    return 0;
}
