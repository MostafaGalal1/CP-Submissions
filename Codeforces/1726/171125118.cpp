#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

void mogalal() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main(){
    mogalal();
    
    ll t;
    cin >> t;

    while (t -- > 0){

        ll n, res = 0;
        string s;
        cin >> n >> s;
        stack<ll> stac;

        for (int i = 0; i < 2 * n; ++i) {


            if (s[i] == '('){
                stac.push(i+1);
            } else {
                res++;
                stac.pop();
            }
            if (s[i] == ')' && s[i + 1] == '(')
                res--;

        }

        cout << res << endl;
    }

    return 0;
}