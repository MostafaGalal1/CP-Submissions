#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        ll n;
        cin >> n;

        for (int i = 2; i < 35; i++){
            if (n%(int)(pow(2,i)-1) == 0){
                cout << n/(int)(pow(2,i)-1) << endl;
                break;
            }
        }
    }
}