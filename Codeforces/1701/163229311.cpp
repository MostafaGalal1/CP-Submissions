#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t --> 0){
        int arr[2][2], count = 0;

        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 1)
                    count++;
            }
        }

        if (count == 0){
            cout << 0 << endl;
        } else if (count < 4){
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}