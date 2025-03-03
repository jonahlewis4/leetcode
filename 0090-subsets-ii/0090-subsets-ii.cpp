class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        calc(0, cur, res, nums);
        return res;
    }
    void calc(int i, vector<int>& cur, vector<vector<int>>& res, const vector<int>& nums){
        if(i >= nums.size()){
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        calc(i + 1, cur, res, nums);
        cur.pop_back();

        int skip = nums[i];
        while(i < nums.size() && nums[i] == skip){
            i++;
        }
        calc(i, cur, res, nums);

    }
};