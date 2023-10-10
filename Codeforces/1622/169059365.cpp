#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll s1, s2, s3, sum, mx;
        cin >> s1 >> s2 >> s3;

        sum = s1 + s2 + s3;
        mx = max(s1, max(s2, s3));

        if (mx == sum - mx || (s1 == s2 && s3%2 == 0) || (s1 == s3 && s2%2 == 0) || (s3 == s2 && s1%2 == 0))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return  0;
}
