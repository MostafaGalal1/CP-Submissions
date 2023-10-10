#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ll a, b, fact = 1;
    cin >> a >> b;
    int mn = (int)min(a, b);
    for (int i = 2; i <= mn; ++i)
        fact *= i;
    cout << fact << endl;
}
