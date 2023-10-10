#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
		int t;
        cin >> t;

		while (t --> 0) {
            map<int, long long> mapp;
            int n, k;
            cin >> n >> k;

            int arr[n + 1];
            long long num, max = 0, m = 0;

            for (int i = 1; i < n + 1; i++) {
                cin >> arr[i];
            }

            arr[0] = 0;
            sort(arr, arr + (n + 1));

            for (int i = 1; i < n + 1; i++) {
                if (arr[i] > arr[i - 1]) {
                    if (mapp.count(k - arr[i] % k))
                        m = (long long) mapp[k - arr[i] % k] + 1LL;
                    else
                        m = 0;
                } else
                    m++;

                if (arr[i] % k == 0) {
                    num = 0;
                } else {
                    num = k - arr[i] % k + k * m;
                    mapp[k - (arr[i] % k)] = m;
                }
                if (num > max)
                    max = num;
            }

            if (max == 0)
                cout << 0;
            else
                cout << (max + 1);
            cout << endl;
        }

    return 0;
}