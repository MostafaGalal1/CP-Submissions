#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        vector<map<string, bool>> v(8);
        int n;
        cin >> n;
        string res, arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            v[arr[i].length()-1][arr[i]] = true;
        }

        for (int i = 0; i < n; i++){
            bool done = false;
            int len = (int)arr[i].length();
            for (int j = 1; j < len; j++){

                string s1 = arr[i].substr(0,j);
                string s2 = arr[i].substr(j,len-j);

                if (v[s1.length()-1][s1] && v[s2.length()-1][s2]){
                    res += "1";
                    done = true;
                    break;
                }
            }
            if (!done)
                res += "0";
        }

        cout << res << endl;
    }
    return 0;
}