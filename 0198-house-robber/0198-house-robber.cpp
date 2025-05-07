class Solution {
    class Recursive{
        const vector<int> &nums;
        int recurse(int n, int total){
            if(n >= nums.size()){
                return total;
            } else {
                //else skip this house and rob the next one
                int skip = recurse(n + 1, total);

                //or rob this house and skip the next one.
                int rob = recurse(n + 2, total + nums[n]);

                return max(skip, rob);
            }   
        }
    public:
        Recursive(const vector<int> &_nums) : nums(_nums) {}
        int Solution(){
            return recurse(0, 0);
        }
    };

    class Memo {
        const vector<int> &nums;
        vector<int> cache;
    private: 
        int recurse(int i){
            if(cache[i] != -1){
                return cache[i];
            }
            int skip = recurse(i + 1);
            int rob = nums[i] + recurse(i + 2);
            int res = max(skip, rob);
            cache[i] = res;
            return res;
        }
    public:
        Memo(const vector<int> &_nums) : nums(_nums){
            cache.resize(_nums.size() + 2, -1);
            cache[_nums.size()] = 0;
            cache[_nums.size() + 1] = 0;
        }
        int Solution() {
            return recurse(0);
        }
    };

    class DP {
    private:
        const vector<int> &nums;
        vector<int> dp;
    public:
        DP(const vector<int> &_nums) : nums(_nums){
            dp.resize(_nums.size() + 2, -1);
            dp[_nums.size()] = 0;
            dp[_nums.size() + 1] = 0;
        }
        int Solution() {
             for(int i = nums.size() - 1; i >= 0; i--){
                int skip = dp[i + 1];
                int use = nums[i] + dp[i + 2];
                int best = max(skip, use);
                
                dp[i] = best;
            }

            return dp[0];
        }
    };

    class DP_Space_Optimized {
    private:
        const vector<int> &nums;
    public:
        DP_Space_Optimized(const vector<int> &_nums) : nums(_nums) {

        }
        inline int Solution(){
            int twoAgo = 0;
            int oneAgo = 0;
            for(int i = nums.size() - 1; i >= 0; i--){
                int skip = oneAgo;
                int rob = nums[i] + twoAgo;
                int best = max(skip, rob);
                twoAgo = oneAgo;
                oneAgo = best;
            }
            return oneAgo;
        }
    };

public:
    int rob(vector<int>& nums) {
        return DP_Space_Optimized(nums).Solution();
    }
    
};