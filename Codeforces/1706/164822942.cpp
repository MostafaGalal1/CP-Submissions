#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n, m;
        cin >> n >> m;
        string s(m, 'B');
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (s[a[i]-1] == 'B' && s[m-a[i]] == 'B')
                if(a[i]-1 <= m-a[i])
                    s[a[i]-1] = 'A';
                else
                    s[m-a[i]] = 'A';
            else if (s[a[i]-1] == 'B')
                s[a[i]-1] = 'A';
            else
                s[m-a[i]] = 'A';
        }

        cout << s << endl;
    }
}