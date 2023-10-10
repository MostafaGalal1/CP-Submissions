#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;

int isprime(unsigned number)
{
    if (number <= 1)
        return 0;
    if (number == 2 || number == 3)
        return 1;
    if (number % 2 == 0 || number % 3 == 0)
        return 0;
    for (unsigned x = 5; x * x <= number; x += 6)
    {
        if (number % x == 0 || number % (x + 2) == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;

    while(t --> 0) {
        int n, number;
        cin >> n;
        number = n;

        while (true){
            if (isprime(number) && !isprime(number - n + 1))
                break;
            else
                number++;
        }

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (i == j)
                    cout << number - n + 1 << " ";
                else
                    cout << 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}