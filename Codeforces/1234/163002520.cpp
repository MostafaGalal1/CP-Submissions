#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    deque<int> q;

    int num;
    for (int i =0 ; i < n; i++){
        cin >> num;
        if (find(q.begin(), q.end(), num) == q.end()) {
            if (q.size() < k)
                q.push_front(num);
            else {
                q.pop_back();
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