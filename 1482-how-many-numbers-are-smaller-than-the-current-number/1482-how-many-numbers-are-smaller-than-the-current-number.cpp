class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> nums2;
        for(int i = 0; i < nums.size(); i++) {
            nums2.push_back({nums[i], i});
        }
        sort(nums2.begin(), nums2.end());
        vector<int> res(nums2.size());
        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i].first;

            pair<int, int> p = {num, 0};
            auto itr = lower_bound(nums2.begin(), nums2.end(), p);
            res[nums2[i].second] = itr - nums2.begin();
        }

        return res;
    }
};