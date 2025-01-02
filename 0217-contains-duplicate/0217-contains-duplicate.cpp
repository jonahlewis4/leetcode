class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> encountered;
        for (const auto & num : nums){
            if(encountered.find(num) != encountered.end()){
                return true;
            }
            encountered.insert(num);
        }
        return false;
    }
};