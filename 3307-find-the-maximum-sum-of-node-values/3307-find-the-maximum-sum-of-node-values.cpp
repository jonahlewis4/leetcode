class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> deltas(nums.size());
        for(int i = 0; i < nums.size(); i++){
            deltas[i] = (nums[i] ^ k) - nums[i];
        }

        sort(deltas.begin(), deltas.end());

        reverse(deltas.begin(), deltas.end());

        long long improvements = 0;

        for(int i = 0; i < nums.size(); i+=2){
            if(i + 1 >= nums.size()){
                break;
            }

            if(deltas[i] + deltas[i + 1] > 0){
                improvements += deltas[i] + deltas[i + 1];
            }
        }   

        long long sum = 0;
        for(const auto & num : nums){
            sum += num;
        }

        return improvements + sum; 
    }
};