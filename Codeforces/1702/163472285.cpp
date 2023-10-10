#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        long long n;
        cin >> n;
        cout << n - (long long)pow(10, (int)log10(n)) << endl;
    }





    return 0;
}