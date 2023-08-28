#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq; // max heap

    pq.push(4);
    pq.push(5);
    pq.push(3);
    pq.push(2);
    cout << "Element at top: " << pq.top() << endl;
    pq.pop();
    cout << "Element at top: " << pq.top() << endl;

    // min heap

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(4);
    pq1.push(5);
    pq1.push(3);
    pq1.push(2);

    cout << "Element at top: " << pq1.top() << endl;
    pq1.pop();
    cout << "Element at top: " << pq1.top() << endl;
}