#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    double h, l;
    cin >> h >> l;

    double hypo = sqrt(h*h + l*l);
    double ang1 = atan(l/h);
    double ang2 = 3.14159265358979323846 - (2*ang1);
    double side = hypo/sin(ang2) * sin(ang1);
    cout << fixed << setprecision(14) << side - h << endl;
}
