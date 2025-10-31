class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> set;
        for(const auto & num : nums) {
            if(set.contains(num)){
                res.push_back(num);
            } else {
                set.insert(num);
            }
        }
        return res;
    }
};