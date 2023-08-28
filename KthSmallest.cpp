#include <bits/stdc++.h>
using namespace std;

int kthsmallest(int arr[], int n, int k)
{
    priority_queue<int> pq; // creates max heap

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top()) // pq is a max heap so if any element smaller than the top will be pushed to it
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
    int ans = kthsmallest(arr, size, k);
    cout << "The Kth smallest element: " << ans;
}