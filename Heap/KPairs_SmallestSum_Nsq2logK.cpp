class myComparison{
    bool min_queue;
public:
    myComparison(const bool& min_q=false)
    {
        min_queue = min_q;
    }
    //now we can handle minque and maxque
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if(min_queue)
            return a.first + a.second > b.first + b.second;
        else
            return a.first + a.second < b.first + b.second;
    }
};

class Solution {
public:
    //o(n^2logk) solution
    //max_heap
    //28ms

    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         //priority_queue<int, vector<int>> pq;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 * size2 == 0)
            return vector<pair<int, int>>();
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, myComparison> maxQ;
        
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                if(maxQ.size() < k)
                    maxQ.push(make_pair(nums1[i], nums2[j]));
                else
                {
                    auto top_pair = maxQ.top();
                    if(top_pair.first + top_pair.second > nums1[i] + nums2[j])
                    {
                        maxQ.pop();
                        maxQ.push(make_pair(nums1[i], nums2[j]));
                    }
                }
            }
        }
        
        //maxQ has the min k pairs
        //maxQ.top() max of theses min k pairs
        //return[pair_1, pair_2, ...., pair_k]
        //sum(pair_1) <= sum(pair_2) <= ... <= sum(pair_k)
        
        vector< pair<int, int>> returns(maxQ.size());
        int i = maxQ.size() - 1;
        while(!maxQ.empty())
        {
            returns[i] = maxQ.top();
            maxQ.pop();
            i--;
        }        
        return returns;
        
    } 
    
};
