class myComparison{
public:
    
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first + a.second < b.first + b.second;
    }
};

class Solution {
public:
    //o(n^2logn) solution2
    //seperate class, shorter, still slow
    //brute force
    //sort
    //smallest
    //196ms

    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         //priority_queue<int, vector<int>> pq;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 * size2 == 0)
            return vector<pair<int, int>>();
        
        vector< pair <int,int>> vp;
        
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                vp.push_back(make_pair(nums1[i], nums2[j]));
            }
        }
        
        sort(vp.begin(), vp.end(), myComparison());
        
        return vector< pair<int, int>>(vp.begin(), vp.begin()
                                    + min(k, (int)vp.size()));
        
    } 
    
};
