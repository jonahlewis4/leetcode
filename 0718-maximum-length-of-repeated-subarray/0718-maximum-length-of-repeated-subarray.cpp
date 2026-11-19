class Solution {
    int best = 0;
    int r(const vector<int>& nums1, const vector<int>& nums2, int i1, int i2) {
        if(i1 >= nums1.size()) {
            return 0;
        }
        if(i2 >= nums2.size()) {
            return 0;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        int res = 0;
        if(nums1[i1] == nums2[i2]) {
            res = 1 + r(nums1, nums2, i1 + 1, i2 + 1);
        }

        dp[i1][i2] = res;

        r(nums1, nums2, i1 + 1, i2);
        r(nums1, nums2, i1, i2 + 1);
        best = max(best, res);
        return res;
    }

    vector<vector<int>> dp;
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        r(nums1, nums2, 0, 0);

        // for(int row = 0; row < nums1.size(); row++) {
        //     for(int col = 0; col < nums2.size(); col++) {
        //         cout<<dp[row][col]<<" ";
        //     }
        //     cout<<endl;
        // }
        return best;
    }
};