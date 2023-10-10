#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N = 1e5 * 2 + 5;

vector<bool> SieveOfEratosthenes()
{
    int n = 1e7 + 5;
    vector<bool> prime(n, true);
    prime[0] = false; prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    }
    return prime;
}


void propagate(int node,int l,int r, vector<int> &seg, vector<int> &lazy)
{
    if (lazy[node] == -2) {
        return;
    }
    seg[node] = lazy[node]*(r-l+1);
    if (l != r) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -2;
}
void update(int node, int l , int r, int st,int en,int val, vector<int> &seg, vector<int> &lazy)
{
    int mid = (l + r) / 2;
    propagate(node, l, r, seg, lazy);
    if (l > en || r < st) {
        return;
    }
    if (l >= st && r <= en) {
        lazy[node] = val;
        propagate(node, l, r, seg, lazy);
        return;
    }
    update(node * 2, l, mid, st, en, val, seg, lazy);
    update(node * 2 + 1, mid + 1, r, st, en, val, seg, lazy);
    seg[node] = seg[node * 2 + 1] + seg[node * 2];
}

int query(int node, int l , int r, int st,int en, vector<int> &seg, vector<int> &lazy)
{
    propagate(node, l, r, seg, lazy);
    if (l > en || r < st)
        return 0;
    if (l >= st && r <= en)
        return seg[node];
    int mid = (l + r) /2;
    return query(node * 2, l, mid, st, en, seg, lazy) + query(node * 2 + 1, mid + 1, r, st, en, seg, lazy);
}

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    vector<int> seg1(N * 4, 0), lazy1(N * 4, -2), seg2(N * 4, 0), lazy2(N * 4, -2);
    vector<bool> primes = SieveOfEratosthenes();

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(1, 0, N, i, i, x, seg2, lazy2);
        if (x <= 1e7 && primes[x]) x = 1; else x = 0;
        update(1, 0, N, i, i, x, seg1, lazy1);
    }

    while (q--)
    {
        char type; cin >> type;
        if (type == 'A')
        {
            int v, l; cin >> v >> l; l--;
            int current = query(1, 0, N, l, l, seg2, lazy2);
            current += v;

            if (current <= 1e7 && primes[current]) v = 1; else v = 0;

            update(1, 0, N, l, l, current, seg2, lazy2);
            update(1, 0, N, l, l, v, seg1, lazy1);
        }
        else if (type == 'R')
        {
            int a, l, r; cin >> a >> l >> r; l--; r--;
            update(1, 0, N, l, r, a, seg2, lazy2);
            if (primes[a]) a = 1; else a = 0;
            update(1, 0, N, l, r, a, seg1, lazy1);
        }
        else
        {
            int x, y; cin >> x >> y; x--, y--;
            int ans = query(1, 0, N, x, y, seg1, lazy1);
            cout << ans << endl;
        }
    }
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();

    int t = 0, i = 0;

//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)
        solve(t, i);
    return 0;;
}

