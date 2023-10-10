#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        long long n = 3, d, prime1 = 0, prime2 = 0;
        cin >> d;

        n = d;

        if (d == 1)
            prime1 = 2;

        while (!prime2) {
            bool done = false;
            for (int i = 2; i < n; i++){
                if (n % i == 0) {
                    done = true;
                    break;
                }
            }
            if (!done){
                if (!prime1) {
                    if (n - 1 >= d) {
                        prime1 = n;
                        n += d-1;
                    }
                } else {
                    if (n - prime1 >= d)
                        prime2 = n;
                }
            }
            n += 1;
        }

        cout << prime1 * prime2 << endl;
    }
    return 0;
}