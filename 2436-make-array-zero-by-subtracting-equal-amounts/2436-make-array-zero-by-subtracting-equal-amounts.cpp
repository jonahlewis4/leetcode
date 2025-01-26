class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set;
        for(const auto & num : nums){
            if(num != 0){
                set.insert(num);
            }
        }
        return set.size();
    }

};