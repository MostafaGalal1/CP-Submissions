#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        unordered_map<int, int> map;

        int n, count = 0, sum = 0;
        cin >> n;
        int arr[n];
        int pre[n];

        for (int i = 0; i < n; i++){
            int num = 0;
            cin >> num;
            arr[i] = num;
            sum += arr[i];
            pre[i] = sum;
            map[num]++;
        }
        for (int j = 1; j < n; j++)
        {
            if (map.count(pre[j]))
            {
                count += map[pre[j]];
                map.erase(pre[j]);
            }
        }

        for (int s = 2; s <= n; s++)
        {
            for (int j = 0; j < n-s && s < n; j++)
            {
                if (map.count(pre[j+s] - pre[j]) > 0)
                {
                    count += map[pre[j+s] - pre[j]];
                    map.erase(pre[j+s] - pre[j]);
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}