#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


void solve(int ttt, int kkkk)
{
    int n, m, x, y; cin >> n >> m >> x >> y; x--, y--;
    int cc = 0;
    for (int i = x; i < n; i++)
    {
        for (int j = y; j < m; j++)
            cout << i + 1 << " " << j + 1 << endl;
        for (int j = 0; j < y; j++)
            cout << i + 1 << " " << j + 1 << endl;
        y--; y+=m; y %= m;
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = y; j < m; j++)
            cout << i + 1 << " " << j + 1 << endl;
        for (int j = 0; j < y; j++)
            cout << i + 1 << " " << j + 1 << endl;
        y--; y+=m; y %= m;
    }
}


void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
//    fast();
//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)
        int i = 1, t = 1;
        solve(t, i);

}




