#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        long long count = 0;
        string s;
        cin >> s;
        vector<char> v;

        for (long long i = 0 ; i < s.length(); i++) {
            if (v.empty()) {
                count++;
            }
            if (v.size() < 3) {
                bool done = false;
                for (char j : v){
                    if (s[i] == j){
                        done = true;
                        break;
                    }
                }
                if (!done)
                    v.push_back(s[i]);
            } else {
                bool done = false;
                for (char j : v) {
                    if (s[i] == j) {
                        done = true;
                        break;
                    }
                }
                if (!done) {
                    v.clear();
                    i--;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}