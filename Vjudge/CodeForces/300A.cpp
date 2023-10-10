#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n;
    vector<int> l;
    vector<int> g;
    vector<int> e;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num == 0)
            e.push_back(num);
        else if (num < 0)
            l.push_back(num);
        else
            g.push_back(num);
    }

    if(g.empty()){
        g.push_back(l.back());
        l.pop_back();
        g.push_back(l.back());
        l.pop_back();
    }

    if (l.size() % 2 == 0) {
        e.push_back(l.back());
        l.pop_back();
    }
    
    cout << l.size() << " ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << "\n";
    cout << g.size() << " ";
    for (int i : g) {
        cout << i << " ";
    }
    cout << "\n";
    cout << e.size() << " ";
    for (int i : e) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}