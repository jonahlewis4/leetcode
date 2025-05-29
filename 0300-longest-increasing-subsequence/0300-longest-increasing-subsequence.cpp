class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longestIncreasingSubsequence(nums.size(), 1);

        //find longest increase subsequence ending at i
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    int other = longestIncreasingSubsequence[j];
                    longestIncreasingSubsequence[i] = max(longestIncreasingSubsequence[i], other + 1);
                }
            }
        }

        return *max_element(longestIncreasingSubsequence.begin(), longestIncreasingSubsequence.end());
    }
};