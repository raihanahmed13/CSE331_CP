#include <bits/stdc++.h>
using namespace std;

int kthlargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // creates min heap

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top()) // pq is a min heap so if any element greater than the top will be pushed to it
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {10, 30, 20, 40, 60, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int ans = kthlargest(arr, size, k);
    cout << "The Kth largest element: " << ans;
}