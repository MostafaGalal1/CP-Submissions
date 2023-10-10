#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        map<char, long long> mapp;
        string s, ss, res;
        long long n, sum = 0;

        cin >> s >> n;
        ss = s;
        sort(s.begin(), s.end());

        for (int i = 0; i < s.length(); ++i) {
            if (sum + (s[i] - 'a' + 1) <= n) {
                sum += s[i] - 'a' + 1;
                mapp[s[i]]++;
            } else
                break;
        }

        for (int i = 0; i < ss.length(); ++i) {
            if (mapp[ss[i]]) {
                res += ss[i];
                mapp[ss[i]]--;
            }
        }

        cout << res << endl;
    }

    return 0;
}