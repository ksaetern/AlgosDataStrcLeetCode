class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //nums.size() >= 2 because each input will have exactly one solution
        int n = nums.size();
        vector <int> ret;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    if(nums[i] + nums[j] == target)
                    {                    
                        ret.push_back(i);
                        ret.push_back(j);
                        return ret;                        
                    }
                }
            }
            
        }
        return ret;
    }
};