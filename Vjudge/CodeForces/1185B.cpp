#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <deque>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        bool done = false;
        string s1, s2;
        int len1, len2, i = 0, j = 0;
        cin >> s1 >> s2;
        len1 = (int)s1.length();
        len2 = (int)s2.length();

        while (i < len1 || j < len2){
            if (s1[i] != s2[j]){
                if (s2[j] == s2[j-1] && j > 0)
                    j++;
                else{
                    done = true;
                    break;
                }
            } else {
                i++;
                j++;
            }
        }

        if (!done)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}