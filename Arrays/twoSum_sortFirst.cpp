class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Sort All the numbers
        //i=0, j=n-1
        //if (nums[i] + nums[j] == target) return (i,j)
        //if (nums[i] + nums[j] > target) -- j
        //if (nums[i] + nums[j] < target) ++i
        //[3,2,1] ==> [1,2,3]
        //pair<int, int> p;
        //p.first -> int p.second ->int
        //Pair<int, int> nums[i], i
        
        vector< pair<int, int> > nums2;
        
        for(int i=0; i < nums.size(); i++)
        {
            pair<int, int> temp(nums[i], i);
            nums2.push_back(temp);
        }
        
        sort(nums2.begin(), nums2.end());
        
        //i=0, j=n-1
        int i = 0;
        int j = nums2.size() - 1;
        while(i < j){
            if(nums2[i].first + nums2[j].first == target){
                vector<int> t{nums2[i].second, nums2[j].second};
                return t;
            }
            else if(nums2[i].first + nums2[j].first > target)
                j--;
            else
                i++;
        }
        return {};
    }
};