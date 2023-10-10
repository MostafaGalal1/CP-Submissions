#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 5e5+7;

void fast() {ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);}

struct node{
    bool flag = false;
    node *nxt[10]{};
    node(){memset(nxt, 0, sizeof(nxt));}
} *root;

bool insert(const string& str) {
    node *cur = root;

    for (int i = 0; i < str.length(); ++i) {
        if (!(cur->nxt[str[i] - '0']) && cur->flag)
            return false;
        if (!(cur->nxt[str[i] - '0']))
            cur->nxt[str[i] - '0'] = new node();
        cur = cur->nxt[str[i] - '0'];
        if (i == str.length() - 1)
            cur->flag = true;
    }
    return true;
}

int main()
{
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        bool done = false;
        root = new node();

        cin >> n;
        string str;
        set<string> st;

        for (int i = 0; i < n; ++i) {
            cin >> str;
            st.insert(str);
        }

        for (const string &i :st) {
            if(!insert(i)) {
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";
        cout << endl;

    }
    return 0;;
}