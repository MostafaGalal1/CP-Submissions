#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    map<int, bool> mapp;
    deque<int> q;

    int num;
    for (int i =0 ; i < n; i++){
        cin >> num;
        if (!mapp[num]) {
            if (q.size() < k) {
                mapp[num] = true;
                q.push_front(num);
            } else {
                mapp[q.back()] = false;
                q.pop_back();
                mapp[num] = true;
                q.push_front(num);
            }
        }
    }

    int size = q.size();
    cout << size << endl;
    for (int i = 0; i < size; i++){
        cout << q.front() << " ";
        q.pop_front();
    }

    cout << endl;

    return 0;
}