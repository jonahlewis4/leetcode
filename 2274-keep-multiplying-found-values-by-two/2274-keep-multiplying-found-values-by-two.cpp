class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set(nums.begin(), nums.end());

        while(set.contains(original)){
            original<<=1;
        }
        return original;
    }
};