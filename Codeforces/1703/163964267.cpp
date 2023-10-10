#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        long long n;
        long long count = 0, trues = 0;
        map<long long, long long> mapp;
        cin >> n;
        long long arr[n];
        bool tru[n];

        for (int i = 1; i < n+1; i++) {
            cin >> arr[i];
            mapp[i] = trues;
            if (arr[i] < i){
                tru[i] = true;
                trues++;
            } else {
                tru[i] = false;
            }
        }

        for (int i = 1; i < n+1; i++) {
            if (tru[i]) {
                count += mapp[arr[i]];
            }
        }

        cout << count << endl;
    }
    return 0;
}