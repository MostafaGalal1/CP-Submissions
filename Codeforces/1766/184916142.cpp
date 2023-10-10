#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){

    ll t;
    cin >> t;

    while (t--> 0) {
        ll n;
        cin >> n;

        cout << (ll)log10(n) *10 + n / (ll)pow(10, (ll)log10(n)) - (ll)log10(n)  << endl;
    }
}