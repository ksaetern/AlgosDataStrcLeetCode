class Solution {
public:
    //O(nlogk) optimized with min_heap
    int findKthLargest(vector<int>& nums, int k) {
       //priority_queue is min_heap, greater<int> makes it min_heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(pq.size() < k)
                pq.push(nums[i]);
            else
            {
                //size() >= k;
                int min_elem = pq.top();
                if(min_elem < nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
   
    }
};