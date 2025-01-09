class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> decreasables(nums.size() + 1, 0);

        for(const auto & query : queries){
            decreasables[query[0]]++;
            decreasables[query[1] + 1]--;
        }

        for(int i = 1; i < decreasables.size(); i++){
            decreasables[i] += decreasables[i - 1];
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > decreasables[i]){
                return false;
            }
        }
        return true;
    }
};