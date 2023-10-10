#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 4e5 + 10;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        int n;
        cin >> n;
        vector<ll> v(n, -1);
        vector<int> sol(n);
        map<int,int> mapp;
        string s;
        cin >> s;

        ll count = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'L')
                count += i;
            if(s[i] == 'R')
                count += n - i - 1;
            if(i < n/2){
                if(s[i] == 'L'){
                    sol[i] = 1;
                }
            }else{
                if(s[i] == 'R'){
                    sol[i] = 1;
                }
            }
        }
        if(n%2)
            sol[n/2] = 0;
        int kk = 0;
        ll i = 0;
        ll j = n-1;

        while(i < j){
            if(sol[i] == 1 && i < n/2){
                count = count - i + n-i-1;
                v[kk++] = count;
            }
            if(sol[j] == 1 && j >=  n/2){
                count = count - (n-j-1) + j;
                v[kk++] = count;
            }
            i++, j--;
        }

        for (int i = kk; i < n; i++)
            v[i] = count;

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        cout << endl;
    }

    return 0;
}