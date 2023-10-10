#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

ll n, m;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void bfs(){
    queue<pair<ll,ll>> q;
    q.push({n,0});
    unordered_map<ll, bool> mapp;

    while (!q.empty()){
        pair<ll,ll> num = q.front();
        q.pop();
        if (num.first <= 0 || mapp[num.first])
            continue;
        mapp[num.first] = true;

        if (num.first == m){
            cout << num.second << endl;
            break;
        } else if (num.first < m)
            q.push({num.first * 2, num.second + 1});
        q.push({num.first - 1, num.second + 1});
    }
}

int main()
{
    fast();
    cin >> n >> m;
    bfs();

    return 0;
}