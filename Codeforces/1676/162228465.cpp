#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int o;
        cin >> o;

        string arr[n];
        int min = INT_MAX;

        cin.ignore();
        for(int j = 0; j < n; j++){
            getline(cin, arr[j]);
        }

        int count = 0;
        for (int j = 0; j < n; j++){
            for (int k = j+1; k < n; k++){
                for (int l = 0; l < o; l++){
                    count += (int)fabs(arr[j][l] - arr[k][l]);
                }
                if (min > count)
                    min = count;
                count = 0;
            }
        }

        cout << min << endl;
    }
}
