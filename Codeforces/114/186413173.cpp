#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t = 1;

    while (t --> 0) {
        string ma = "lios";
        string fa = "liala";
        string mn = "etr";
        string fn = "etra";
        string mv = "initis";
        string fv = "inites";

        string cc;
        getline(cin,cc);

        istringstream iss(cc);
        string word;

        ll xo;
        bool done = false;
        bool first = true;
        bool noun = false;
        bool verb = false;
        ll cnt = 0;
        while(iss >> word) {
            cnt++;
            if (first){
                if ((word.size() >= 4 && word.substr(word.size() - 4, word.size()) == ma) || (word.size() >= 3 && word.substr(word.size() - 3, word.size()) == mn)) {
                    xo = 0;
                    if (word.size() >= 3 && word.substr(word.size() - 3, word.size()) == mn){
                        noun = true;
                    }
                } else if ((word.size() >= 5 && word.substr(word.size() - 5, word.size()) == fa) || (word.size() >= 4 && word.substr(word.size() - 4, word.size()) == fn)) {
                    xo = 1;
                    if (word.size() >= 4 && word.substr(word.size() - 4, word.size()) == fn) {
                        noun = true;
                    }
                } else if (((word.size() >= 6 && word.substr(word.size() - 6, word.size()) == mv)) || ((word.size() >= 6 && word.substr(word.size() - 6, word.size()) == fv))){
                    verb = true;
                } else {
                    cout << "NO";
                    done = true;
                    break;
                }
                first = false;
            } else {
                if (verb){
                    cout << "NO";
                    done = true;
                    break;
                }
                if (!noun){
                    if (((word.size() >= 4 && word.substr(word.size() - 4, word.size()) == ma) || (word.size() >= 3 && word.substr(word.size() - 3, word.size()) == mn)) && xo == 0) {
                        if (word.size() >= 3 && word.substr(word.size() - 3, word.size()) == mn){
                            noun = true;
                        }
                    } else if (((word.size() >= 5 && word.substr(word.size() - 5, word.size()) == fa) || (word.size() >= 4 && word.substr(word.size() - 4, word.size()) == fn)) && xo == 1){
                        if (word.size() >= 4 && word.substr(word.size() - 4, word.size()) == fn){
                            noun = true;
                        }
                    } else {
                        cout << "NO";
                        done = true;
                        break;
                    }
                } else {
                    if ((word.size() >= 6 && word.substr(word.size() - 6, word.size()) == mv) && xo == 0) {
                    } else if ((word.size() >= 6 && word.substr(word.size() - 6, word.size()) == fv) && xo == 1){
                    } else {
                        cout << "NO";
                        done = true;
                        break;
                    }
                }
            }
        }

        if (!done) {
            if ((cnt > 1 && noun) || cnt <= 1)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
    return 0;
}