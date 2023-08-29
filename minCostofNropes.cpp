/*There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.*/

#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int> arr)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    // priority_queue<int, vector<int>, greater<int>> pq;
    // for (int i : arr)
    // {
    //     pq.push(i);
    // }

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        ans += sum;
        pq.push(sum);
    }

    return ans;
}
int main()
{
    vector<int> arr = {4, 3, 2, 6};
    int ans = minCost(arr);
    cout << "Min cost to connect " << arr.size() << " ropes: " << ans;
}