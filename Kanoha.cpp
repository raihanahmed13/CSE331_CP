#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, z, num;
        cin >> n >> z;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            pq.push(num);
        }
        int hits = 0;
        while (pq.top() != 0 && z > 0)
        {
            hits++;
            num = pq.top();
            z = z - num;
            pq.pop();
            pq.push(num / 2);
        }
        if (z > 0)
        {
            cout << "Evacuate" << endl;
        }
        else
        {
            cout << hits << endl;
        }
    }
    return 0;
}
