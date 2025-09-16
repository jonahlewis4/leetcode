class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long best = -1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size(); k++){
                    best = max(best, ((long long)nums[i] - nums[j]) * nums[k]);
                }
            }

        }
        return best == -1 ? 0 : best;
    }
};