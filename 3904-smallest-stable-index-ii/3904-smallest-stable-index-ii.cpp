class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mn(nums.size());
        mn.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], nums[i]);
        }

        int high = nums.front();
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            high = max(high, num);
            int instab = high - mn[i];
            if(instab <= k) {
                return i;
            }
        }
        return -1;
    }
};