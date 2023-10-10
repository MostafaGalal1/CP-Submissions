#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 3010;

string s1, s2;
int l1, l2;
int mapp[N][N];

int solve(int sl1, int sl2){
    if (sl1 == l1 || sl2 == l2)
        return 0;

    if (~mapp[sl1][sl2])
        return mapp[sl1][sl2];

    if (s1[sl1] == s2[sl2]) {
        return mapp[sl1][sl2] = solve(sl1 + 1, sl2 + 1) + 1;
    } else {
        mapp[sl1][sl2 + 1] = solve(sl1, sl2 + 1);
        mapp[sl1 + 1][sl2] = solve(sl1 + 1, sl2);
        return max(mapp[sl1][sl2 + 1], mapp[sl1 + 1][sl2]);
    }
}

string s;
void builder (int sl1, int sl2){
    if (sl1 == l1 || sl2 == l2)
        return;

    if (s1[sl1] == s2[sl2]){
        s += s1[sl1];
        builder(sl1 + 1, sl2 + 1);
        return;
    }

    if (solve(sl1, sl2+1) > solve(sl1+1, sl2)){
        builder(sl1, sl2+1);
    } else {
        builder(sl1+1, sl2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mapp, -1, sizeof mapp);

    cin >> s1 >> s2;
    l1 = s1.length(), l2 = s2.length();

    builder(0, 0);

    cout << s << endl;
    return 0;
}