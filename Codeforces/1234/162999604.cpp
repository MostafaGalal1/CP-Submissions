#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t --> 0){
        int n;
        long long sum = 0;
        cin >> n;

        for (int i =0 ; i < n; i++){
            int num;
            cin >> num;
            sum += num;
        }

        cout << (long long)ceil(sum * 1.0 / n) << endl;
    }

    return 0;
}