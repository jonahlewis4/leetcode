class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> nums2;
        for(int i = 0; i < nums.size(); i++) {
            nums2.push_back({nums[i], i});
        }
        sort(nums2.begin(), nums2.end());
        vector<int> res(nums2.size());

        int lt = 0;
        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i].first;

            if(i > 0 && nums2[i - 1].first < nums2[i].first){
                lt = i;
            }            
            res[nums2[i].second] = lt;
        }

        return res;
    }
};