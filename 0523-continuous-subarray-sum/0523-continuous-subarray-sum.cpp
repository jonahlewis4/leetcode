class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        vector<bool> found(k);
        found[0] = true;
        int prev = -1;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            sum += num;
            sum %= k;
            if(found[sum] && (num % k) > 0) {
                return true;
            }
            if((num % k) == 0 && prev == 0) {
                return true;
            }


            found[sum] = true;
            prev = num % k;
        }
        return false;
    }
};