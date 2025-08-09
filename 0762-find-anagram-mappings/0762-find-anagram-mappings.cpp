class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> iList;
        for(int i = 0; i < nums2.size(); i++) {
            iList[nums2[i]] = i;
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            ans[i] = iList[nums1[i]];
        }
        return ans;
    }
};