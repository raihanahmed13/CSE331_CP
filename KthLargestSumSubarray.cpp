#include <bits/stdc++.h>
using namespace std;
int kthlargest(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j]; // storing sum of subarrays
            if (pq.size() < k)
            { // so that only k elements will store in heap
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum); // to make the top element our answer
                }
            }
        }
    }

    return pq.top();
}
int main()
{
    vector<int> arr = {4, 5, 2, 8}; // subarrays: [4],[4,5],[4,5,2],[4,5,2,8],........
    int k = 3;
    int ans = kthlargest(arr, k);
    cout << "The " << k << "th largest sum subarray: " << ans;
}