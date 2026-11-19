class Solution {

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        vector<int> dp(nums2.size(), 0);
        int best = 0;
        for(int r = nums1.size() - 1; r >= 0; r--) {
            int bottomRight = 0;
            for(int c = nums2.size() - 1; c >= 0; c--) {
                int bottom = dp[c];
                int res = 0;

                if(nums1[r] == nums2[c]) {
                    res = 1 + bottomRight;
                }

                best = max(best, res);
                dp[c] = res;
                bottomRight = bottom;
            }
        }
        
        return best;
    }
};