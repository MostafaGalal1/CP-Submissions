#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, count, maxx = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        bool le = true, ri = true;
        int l = i-1, r = i+1;
        count = 1;
        while (le || ri){
            if (r == n)
                ri = false;
            if (l == -1)
                le = false;
            if (ri && arr[r] <= arr[r-1]){
                count++;
                r++;
            } else {
                ri = false;
            }
            if (le && arr[l] <= arr[l+1]){
                count++;
                l--;
            } else {
                le = false;
            }
        }

        if (count > maxx)
            maxx = count;
    }

    cout << maxx << endl;

    return 0;
}