#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 510;

int main() {

    ll n;

    while(cin >> n) {
        if (n == 0)
            break;

        vector<ll> arr(n);

        while (cin >> arr[0]) {
            if (arr[0] == 0) {
                cout << endl;
                break;
            }

            bool done = false;

            stack<ll> st;

            for (int i = 1; i < n; ++i) {
                cin >> arr[i];
            }

            ll count = 1;
            ll ind = 0;
            while (count <= n) {
                while (count <= arr[ind])
                    st.push(count++);

                while (!st.empty()) {
                    if (st.top() == arr[ind]) {
                        st.pop();
                        ind++;
                    } else if (arr[ind] > st.top()){
                        break;
                    } else {
                        done = true;
                        break;
                    }
                }
                if (done)
                    break;
            }

            if (!done)
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
    }
    return 0;;
}