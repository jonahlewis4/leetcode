class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int used = 0;
        for(int i = 0; i < min((int)nums.size(), k); i++) {
            if(nums[i] >= 0) {
                break;
            }

            used++;
            nums[i] = -nums[i];
        }

        int remaining = k - used;
        
        


        if(remaining % 2 == 0) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
        return accumulate(nums.begin(), nums.end(), 0);
        
    }
};