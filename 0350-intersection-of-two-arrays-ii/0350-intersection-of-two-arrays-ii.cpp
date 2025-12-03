class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        

        unordered_map<int, int> count;
        for(const int i : nums1) {
            count[i]++;
        }

        vector<int> res;
        for(const int i : nums2) {
            if(count[i] > 0){
                count[i]--;
                res.push_back(i);
            }
        }

        return res;
    }
};