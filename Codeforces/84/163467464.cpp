#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, count = 0, sum = 0;
    cin >> n;
    long long arr[n+1];

    arr[0] = INT_MAX;
    for (long long i = 1; i <= n; i++){
        cin >> arr[i];
        if (arr[i] != arr[i-1]) {
            sum += count * (count + 1) / 2;
            count = 1;
        } else
            count++;
    }

    sum += count * (count + 1) / 2;
    cout << sum << endl;
    return 0;
}