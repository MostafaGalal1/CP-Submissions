#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string st, res;
const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;
vector<map<string, int>> a(N);

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, nn, cnt = 0, ind = -1;
        cin >> n;
        nn = n;

        for (int i = 0; i < 32; ++i) {
            cnt += n&1;
            if (n&1 && !~ind)
                ind = i;
            n >>= 1;
        }

        if (cnt > 1){
            cout << (1 << ind);
        } else {
            if (ind)
                cout << (nn|1);
            else
                cout << (nn|2);
        }
        cout << endl;
    }
    return 0;
}