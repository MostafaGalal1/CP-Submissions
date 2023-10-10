#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    double n, x1, y1, x2, y2, d;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    d = abs(x1-x2) + abs(y1-y2);
    if (abs(x1 - x2) == n)
        d += 2 * min(min(y1, y2), min(n- y1, n -y2));
    else if (abs(y1 - y2) == n)
        d += 2 * min(min(x1, x2), min(n- x1, n -x2));

    cout << d << endl;
    return 0;
}