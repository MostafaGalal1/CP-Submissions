#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void solve()
{
    ll n, mni, mxi;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i], arr[i]--;
    vector<int> pos(n); for (int i = 0; i < n; i++) pos[arr[i]] = i;

    int l = 0, r = n - 1;

    set<int> sett; for (int i = 0; i < n; i++) sett.emplace(i);

    while (sett.size() >= 2)
    {
        int mini = *sett.begin(), maxi = *sett.rbegin();

        if (arr[l] == mini || arr[l] == maxi)
        {
            sett.erase(arr[l]);
            l++;
        }
        else if (arr[r] == mini || arr[r] == maxi)
        {
            sett.erase(arr[r]);
            r--;
        }
        else
        {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }

    }
    cout << -1 << endl;
}

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
     solve();
    }

    return 0;
}
