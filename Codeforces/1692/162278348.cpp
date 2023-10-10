#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n = 0;
        int num = 0;
        int count = 0;
        cin >> n;
        
        for (int j = 0 ; j < 3; j++){
            cin >> num;
            if (n < num)
                count++;
        }
        
        cout << count << endl;
    }
    return 0;
}