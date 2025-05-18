class Solution {
private:
    vector<int> sizes;
    vector<int> nums;
    int k;
    vector<vector<int>> dp;
    int maxSumFrom(int start, int splitNumber){
            if(start + k > nums.size() || splitNumber >= 3){
                return 0;
            }
            
            if(dp[start][splitNumber] != -1){
                return dp[start][splitNumber];
            }
            //use this one or skip it

            int use = sizes[start] + maxSumFrom(start + k, splitNumber + 1);
            int skip = maxSumFrom(start + 1, splitNumber);
            dp[start][splitNumber] = max(use, skip);
            return max(use, skip);
        }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
      

        int kSum = 0;
        sizes.resize(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            kSum += nums[i];
            if(i + 1 - k >= 0){
                sizes[i + 1 - k] = kSum;
                kSum -= nums[i + 1 - k];
            }
        }

        dp.resize(nums.size() - k + 1, vector<int>(3, -1));




        vector<int> starts;
        int i = 0; 
        while(i <= nums.size() - k && starts.size() < 3){
            int use = sizes[i] + maxSumFrom(i + k, starts.size() + 1);
            int skip = maxSumFrom(i + 1, starts.size());

            if(use >= skip) {
                starts.push_back(i);
                i += k;
            } else {
                i++;
            }


        }        
        
        return starts;

    }
};