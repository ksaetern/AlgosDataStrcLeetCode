class Solution {
public:
    //O(nlogn) optimized with min_heap
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        return (nums[size - k]);
        
    }
};