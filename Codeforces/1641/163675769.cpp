#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    long long t;
    cin >> t;

    while (t --> 0) {
        long long n, x, count = 0;
        map<long long, long long> mapp;
        cin >> n >> x;
        long long arr[n];

        long long num;
        for (long long i = 0; i < n; ++i) {
            cin >> num;
            arr[i] = num;
            mapp[num]++;
        }

        sort(arr, arr + n);

        for (long long i = 0; i < n; i++) {
            num = arr[i];
            if (mapp[num] <= 0)
                continue;
            if (mapp[num * x]) {
                mapp[num * x]--;
            } else {
                count++;
            }
            mapp[num]--;
        }

        cout << count << endl;
    }
}