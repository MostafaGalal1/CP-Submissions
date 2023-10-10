#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int main() {
    string s;
    bool pos = true;
    ull n;
    cin >> s;

    if (s.length() > 19){
cout << "BigInteger";
    } else {
        if(s[0]=='-') {
            pos = false;
            n = stoull(s.substr(1, s.length() - 1), nullptr, 10);
        } else
            n = stoull(s, nullptr, 10);

        if ((n > 9223372036854775807 && pos) || (n > 9223372036854775808 && !pos)){
cout << "BigInteger";
        } else if ((n > 2147483647 && pos) || (n > 2147483648 && !pos)){
cout << "long";
        } else if ((n > 32767 && pos) || (n > 83276 && !pos)){
cout << "int";
        } else if ((n > 127 && pos) || (n > 128 && !pos)){
cout << "short";
        } else {
cout << "byte";
        }
    }
return 0;
}