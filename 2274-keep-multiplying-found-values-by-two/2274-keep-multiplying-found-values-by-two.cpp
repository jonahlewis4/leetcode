class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        uint og = (uint) original;
        unordered_set<int> set;
        for(const int i : nums) {
            set.insert(i);
        }

        while(set.contains(og)){
            og<<=1;
        }
        return og;
    }
};