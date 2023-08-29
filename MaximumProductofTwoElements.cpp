//link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int m1=pq.top();
        pq.pop();
        
        return (m1-1)*(pq.top()-1);
    }
};
