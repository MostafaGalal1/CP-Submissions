#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() {ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);}

struct node{
    vector<ll> loc;
    node *nxt[26]{};
    node(){memset(nxt, 0, sizeof(nxt));}
} *root;

void insert(const string& str, ll ind) {
    node *cur = root;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            cur->nxt[i - 'a'] = new node();
        cur = cur->nxt[i - 'a'];
        cur->loc.push_back(ind);
    }
}

vector<ll> query(const string& str) {
    node *cur = root;
    vector<ll> emp;
    for (char i : str) {
        if (!(cur->nxt[i - 'a']))
            return emp;
        cur = cur->nxt[i - 'a'];
    }
    return cur->loc;
}

int main()
{
    fast();

    ll n, q;
    root = new node();

    cin >> n;
    string str;
    set<string> st;
    vector<string> ve;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        st.insert(str);
    }

    ll ind = 0;
    for (const string & i : st){
        insert(i, ind);
        ve.push_back(i);
        ind++;
    }

    cin >> q;
    vector<ll> res;

    for (int i = 1; i <= q; ++i) {
        cin >> str;
        res = query(str);
        cout << "Case #" << i << ":" << endl;
        if (res.empty())
            cout << "No match." << endl;
        else {
            for (long long re : res) {
                if (ve[re] == str)
                    continue;
                cout << ve[re] << endl;
            }
        }
    }

    return 0;
}