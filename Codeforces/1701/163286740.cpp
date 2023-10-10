#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t --> 0){
        map<int, bool> mapp;
        int n;
        cin >> n;

        cout << 2 << endl;
        cout << 1 << " ";
        mapp[1] = true;

        int num;
        for (int i = 2; i <= n; i++) {
            num = i;
            while (num <= n && !mapp[num]) {
                mapp[num] = true;
                cout << num << " ";
                num *= 2;
            }
        }

        cout << endl;
    }

    return 0;
}