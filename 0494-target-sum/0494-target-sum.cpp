class Solution {
    class SubsetSumCount{
        static constexpr int MOD = 1e9 + 7;
        const vector<int>& nums;
        int target;
    public:
        SubsetSumCount(const vector<int>& nums, int target) : nums(nums), target(target) {}
        int Recursive() const {
            return recurse(0, 0);
        }
        int recurse(int i, int sum) const {
            if(i >= nums.size() && sum == target){
                return 1;
            }
            if(i >= nums.size() && sum != target) {
                return 0;
            }

            int use = recurse(i + 1, sum + nums[i]);
            int skip = recurse(i + 1, sum);
            return (use + skip) % MOD;
        }

        int Memo() {
            vector<vector<int>> cache(nums.size(), vector<int>(target + 1, -1));
            return recurseMemo(0, 0, cache);
        }
        int recurseMemo(int i, int sum, vector<vector<int>>& cache){
            if(sum > target) {
                return 0;
            }
            if(i >= nums.size() && sum == target){
                return 1;
            }
            if(i >= nums.size() && sum != target) {
                return 0;
            }
            if(cache[i][sum] != -1){
                return cache[i][sum];
            }
            int use = recurseMemo(i + 1, sum + nums[i], cache);
            int skip = recurseMemo(i + 1, sum, cache);
            cache[i][sum] = (use + skip) % MOD;
            return cache[i][sum];
        }
    };
public:
    int findTargetSumWays(vector<int>& nums, int target) {  
        int sum = 0;
        for(const auto & num : nums) {
            sum += num;
        }
        if(sum < target) {
            return 0;
        }

        if((sum + target) % 2 == 1 || (sum + target) < 0) {
            return 0;
        }

        int newSum = (sum + target) / 2; 

        return SubsetSumCount(nums, newSum).Memo();
    }
};