class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int longest = 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> count;
        while(r < nums.size()) {
            int newNum = nums[r];

            count[newNum]++;
            while(count[newNum] > k) {
                count[nums[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);

            r++;
        }

        return longest;
    }
};