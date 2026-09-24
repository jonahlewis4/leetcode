class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_set<int> found;
        found.insert(0);
        int prev = -1;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            sum += num;
            sum %= k;
            if(found.contains(sum) && (num % k) > 0) {
                return true;
            }
            if((num % k) == 0 && prev == 0) {
                return true;
            }


            found.insert(sum);
            prev = num % k;
        }
        return false;
    }
};