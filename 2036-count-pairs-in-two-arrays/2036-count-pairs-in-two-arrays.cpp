class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long pairs = 0;
        int n = nums1.size();
        vector<int> diff(nums1.size());
        for(int i = 0; i < n; i++){
            diff[i] = nums1[i] - nums2[i];
        }

        sort(diff.begin(), diff.end());
        int l = 0;
        int r = diff.size() - 1;
        while(l < r) {
            int sum = diff[l] + diff[r];
            if(sum > 0) {
                pairs += r - l;
                r--;
            } else {
                l++;
            }
        }
        return pairs;
    }
};