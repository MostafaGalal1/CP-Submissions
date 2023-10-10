#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ll n, k, num;
    cin >> n;

    n--;
    k = (ll)log2(n/5 + 1);
    num = ((n - 5 * ((ll)pow(2,k) - 1))/((ll)pow(2,k))) % 5;

    if (num == 0)
        cout << "Sheldon";
    else  if (num == 1)
        cout << "Leonard";
    else  if (num == 2)
        cout << "Penny";
    else  if (num == 3)
        cout << "Rajesh";
    else
        cout << "Howard";
    cout << endl;
    return 0;
}