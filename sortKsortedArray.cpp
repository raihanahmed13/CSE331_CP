#include <bits/stdc++.h>
using namespace std;
vector<int> nearlySorted(vector<int> arr, int n, int k)
{
    vector<int> ans;
    int s = (n == k) ? k : k + 1; // keeping the size of priority queue to k+1 or k
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + s);

    for (int i = pq.size(); i < n; i++)
    {
        ans.push_back(pq.top()); // pushing the min elements to ans vector till all elements of arr is traversed
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty()) // pushing rest of the elements of pq to ans vector
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> ans = nearlySorted(arr, arr.size(), k);

    cout << "After sorting: " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
}