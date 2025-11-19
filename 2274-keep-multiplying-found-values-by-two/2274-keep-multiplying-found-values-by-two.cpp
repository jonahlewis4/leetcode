class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set;
        for(const int i : nums) {
            set.insert(i);
        }

        while(set.contains(original)){
            original<<=1;
        }
        return original;
    }
};