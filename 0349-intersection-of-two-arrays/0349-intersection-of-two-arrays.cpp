class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;

        for(const auto & num : nums1){
            set.insert(num);
        }
        vector<int> res;

        for(const auto & num : nums2){
            if(set.find(num) != set.end()){
                res.push_back(num);
            }
            set.erase(num);
        }

        


        return res;
    }
};