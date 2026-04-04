class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(const int i : nums1) {
            s1.insert(i);
        }
        for(const int i : nums2) {
            s2.insert(i);
        }

        vector<vector<int>> res = {{},{}};
        for(const int i : nums1) {
            if(!s2.contains(i)){
                s2.insert(i);
                res.front().push_back(i);
            }
        }
        for(const int i : nums2) {
            if(!s1.contains(i)){
                s1.insert(i);
                res.back().push_back(i);
            }
        }

        return res;

    }
};