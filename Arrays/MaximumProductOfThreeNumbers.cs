public class Solution {
    //O(n) Solution, Keep track of the biggest and smallest numbers
    //Run it once to grab all the numbers
    //calculate after
    public int MaximumProduct(int[] nums) {
        int size = nums.Length;
        int[] maxNums = {-1001, -1000, -999};
        int[] minNums = {0, 0};
        
        for(int i = 0; i < size; i++){
            if(nums[i] > maxNums[0]){
                maxNums[2] = maxNums[1];
                maxNums[1] = maxNums[0];
                maxNums[0] = nums[i];
            }
            else if(nums[i] > maxNums[1]){
                maxNums[2] = maxNums[1];
                maxNums[1] = nums[i];
            }
            else if(nums[i] > maxNums[2]){
                maxNums[2] = nums[i];
            }
            if(nums[i] < 0){
                if(nums[i] < minNums[0]){
                    minNums[1] = minNums[0];
                    minNums[0] = nums[i];
                }
                else if(nums[i] < minNums[1]){
                    minNums[1] = nums[i];
                }
            }
        }
        
        int m1 = maxNums[0] * maxNums[1] * maxNums[2];
        int m2 = minNums[0] * minNums[1] * maxNums[0];
        
        int max = m1 < m2 ? m2: m1;
        return max;
    }
}