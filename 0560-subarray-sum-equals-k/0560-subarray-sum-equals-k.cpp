class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> numCSum;
        numCSum[0] = 1;
        
        int cSum = 0;
        int matches = 0;
        for(int i = 0; i < nums.size(); i++){
            //see how many times the difference exists
            cSum += nums[i];
            matches += numCSum[cSum - k];
            numCSum[cSum]++;
        }
        return matches;

    }

    
    
};