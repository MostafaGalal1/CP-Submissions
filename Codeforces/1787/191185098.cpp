#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
map<int, int> mapp;

void factors(int n) {
    while (n%2 == 0){
        mapp[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            mapp[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        mapp[n]++;
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        int n;
        ll sum = 0;
        bool done = false;
        cin >> n;

        factors(n);

        while (!done) {
            ll num = 1;
            done = true;
            for (auto i: mapp) {
                if (i.second){
                    num *= i.first;
                    mapp[i.first]--;
                    done = false;
                }
            }
            sum += num;
        }
        cout << sum-1 << endl;
    }
    return 0;
}