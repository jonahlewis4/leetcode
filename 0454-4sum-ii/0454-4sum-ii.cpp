class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums;
        for(const int num : nums3) {
            for(const int num2 : nums4) {
                sums[num + num2]++;
            }
        }

        int res = 0;
        for(const int num : nums1) {
            for(const int num2: nums2) {
                int sum = num + num2;
                if(sums.contains(-sum)) {
                    res += sums[-sum];
                }
            }
        }
        return res;
    }
};