#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, res = 0, count = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.' && i != n-1)
            count++;
        else {
            if (i == n-1 && s[n-1] == '.')
                count++;

            if (count % 2){
                if (a >= count / 2 && b >= count / 2){
                    res += count/2 * 2;
                    a-= count / 2;
                    b-= count / 2;
                    if (a >= b && a) {
                        res++;
                        a--;
                    } else if (b >= a && b) {
                        res++;
                        b--;
                    }
                } else if (a >= count / 2 && b <= count / 2){
                    res += count / 2 + b;
                    a-= count / 2;
                    b = 0;
                    if (a) {
                        res++;
                        a--;
                    }
                } else if (b >= count / 2 && a <= count / 2){
                    res += count / 2 + a;
                    b-= count / 2;
                    a = 0;
                    if (b) {
                        res++;
                        b--;
                    }
                } else {
                    res += a + b;
                    a = 0;
                    b = 0;
                }
            } else {
                if (a >= count / 2 && b >= count / 2){
                    res += count;
                    a-= count / 2;
                    b-= count / 2;
                } else if (a >= count / 2 && b <= count / 2){
                    res += count / 2 + b;
                    a-= count / 2;
                    b = 0;
                } else if (b >= count / 2 && a <= count / 2){
                    res += count / 2 + a;
                    b-= count / 2;
                    a = 0;
                } else {
                    res += a + b;
                    a = 0;
                    b = 0;
                }
            }
            count = 0;
        }
    }

    cout << res << endl;

    return 0;
}