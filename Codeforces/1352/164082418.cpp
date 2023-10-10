#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t --> 0) {
        long long n, f, s, sum = 0, presum = 0, turn = 1;
        long long moves = 0, a = 0, b = 0;
        cin >> n;
        f = -1;
        s = n;
        long long arr[n];

        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }

        while (f != s-1){
            if (turn) {
                f++;
                sum += arr[f];
                a += arr[f];
                if (sum > presum) {
                    moves++;
                    presum = sum;
                    sum = 0;
                    turn = 0;
                }
            } else {
                s--;
                sum += arr[s];
                b += arr[s];
                if (sum > presum) {
                    moves++;
                    presum = sum;
                    sum = 0;
                    turn = 1;
                }
            }
        }

        if (sum)
            moves++;

        cout << moves << " " << a << " " << b << endl;
    }
    return 0;
}