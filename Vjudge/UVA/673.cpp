#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf ("%d",&n);
    getchar();

    while (n --> 0){
        stack<char> st;
        while (!st.empty())
            st.pop();
        bool done = false;
        char s[130]={0};
        gets(s);


        for (char &i : s) {
            if (i == ')'){
                if (!st.empty() && st.top() == '('){
                    st.pop();
                } else {
                    done = true;
                    break;
                }
            } else if (i == ']'){
                if (!st.empty() && st.top() == '['){
                    st.pop();
                } else {
                    done = true;
                    break;
                }
            } else if (i == '(' || i == '['){
                st.push(i);
            }
        }

        if (!done && st.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}