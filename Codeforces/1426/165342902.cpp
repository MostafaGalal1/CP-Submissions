#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t --> 0) {
        int n, m;
        cin >> n >> m;

    if (n < 3)
        cout << 1 << endl;
    else
        cout << (n - 3)/m + 2 << endl;
    }

    return 0;
}