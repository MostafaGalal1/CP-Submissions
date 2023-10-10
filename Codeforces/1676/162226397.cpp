#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++){
        string s;
        getline(cin, s);
        char arr[s.length()+1];
        strcpy(arr, s.c_str());

        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < s.length()/2; j++){
            sum1 += arr[j] - '0';
            sum2 += arr[s.length()-1-j] - '0';
        }

        if (sum1 == sum2){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
