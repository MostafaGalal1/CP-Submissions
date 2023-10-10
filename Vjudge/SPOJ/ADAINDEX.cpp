#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6+7;

struct node{
    ll cnt = 0;
    node *nxt[26]{};
    node(){memset(nxt, 0, sizeof(nxt));}
} *root;

void insert(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            cur->nxt[i - 'a'] = new node();
        cur = cur->nxt[i - 'a'];
        cur->cnt++;
    }
}

ll query(const string& str) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            return 0;
        cur = cur->nxt[i - 'a'];
    }
    return cur->cnt;
}

int main()
{
    ll n, q;
    root = new node();

    cin >> n >> q;
    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        insert(str);
    }

    for (int i = 0; i < q; ++i) {
        cin >> str;
        cout << query(str) << endl;;
    }

    return 0;
}