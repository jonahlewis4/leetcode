class Solution {
    // int r(const vector<int>& nums1, const vector<int>& nums2, int i1, int i2) {
    //     if(i1 >= nums1.size()) {
    //         return 0;
    //     }
    //     if(i2 >= nums2.size()) {
    //         return 0;
    //     }

    //     if(dp[i1][i2] != -1){
    //         return dp[i1][i2];
    //     }

    //     int res = 0;
    //     if(nums1[i1] == nums2[i2]) {
    //         res = 1 + r(nums1, nums2, i1 + 1, i2 + 1);
    //     }

    //     dp[i1][i2] = res;

    //     r(nums1, nums2, i1 + 1, i2);
    //     r(nums1, nums2, i1, i2 + 1);
    //     best = max(best, res);
    //     return res;
    // }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        vector<int> dp(nums2.size(), 0);
        int best = 0;
        for(int r = nums1.size() - 1; r >= 0; r--) {
            int bottomRight = 0;
            int right = 0;
            for(int c = nums2.size() - 1; c >= 0; c--) {
                int bottom = dp[c];
                int res = 0;

                if(nums1[r] == nums2[c]) {
                    res = 1 + bottomRight;
                }

                best = max(best, res);
                dp[c] = res;
                bottomRight = bottom;
                right = dp[c];
            }
        }
        
        return best;
    }
};