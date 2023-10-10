#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 5e5+7;

unordered_map<string, ll> mapp;

void fast() {ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);}

struct node{
    string cs;
    node *nxt[26]{};
    node(){memset(nxt, 0, sizeof(nxt));}
} *root;

void insert(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            cur->nxt[i - 'a'] = new node();
        cur = cur->nxt[i - 'a'];
        if ((mapp[cur->cs] < mapp[str]) || (mapp[cur->cs] == mapp[str] && str < cur->cs))
            cur->cs = str;
    }
}

pair<string, ll> query(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            return {"", -1};
        cur = cur->nxt[i - 'a'];
    }
    return {cur->cs, mapp[cur->cs]};
}

int main()
{
    fast();

    ll n, q;
    root = new node();

    cin >> n;
    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        mapp[str]++;
        insert(str);
    }

    cin >> q;
    pair<string, ll> p;
    for (int i = 0; i < q; ++i) {
        cin >> str;
        p = query(str);
        p.first.empty()? cout << -1:cout << p.first << ' ' << p.second;
        cout << endl;;
    }

    return 0;
}