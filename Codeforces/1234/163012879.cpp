#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool solve(int x, int y, vector<vector<char>> &a) {
    if (x == n){
        if (y == 1)
            return true;
        else
            return false;
    }


    if (a[x][y] - '0' > 2){
        if (y == 0 && (a[x][1] - '0') > 2)
            return solve(x+1,1,a);
        else if (y == 1 && (a[x][0] - '0') > 2)
            return solve(x+1,0,a);
        else
            return false;
    } else {
        if (x+1 == n){
            if (y == 0)
                return false;
            else
                return true;
        }
        if (y == 0 && (a[x+1][0] - '0') > 2 && (a[x+1][1] - '0') > 2)
            return solve(x+1,0,a);
        else if (y == 1 && (a[x+1][0] - '0') > 2 && (a[x+1][1] - '0') > 2)
            return solve(x+1,1,a);
        else if ((a[x+1][y] - '0') < 3)
            return solve(x+1,y,a);
        else
            return false;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        cin >> n;

        vector<vector<char>> arr(n, vector<char>(2));
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[j][i];
            }
        }

        if (solve(0, 0, arr))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}