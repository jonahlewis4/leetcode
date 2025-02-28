class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur = {};
        dfs(nums, res, cur);
        return res;
    }
    void dfs(const vector<int> & nums, vector<vector<int>> &res, vector<int>& cur){
        res.push_back(cur);
        for(const int num : nums){
            if(cur.empty() || num > cur.back()){
                cur.push_back(num);
                dfs(nums, res, cur);
                cur.pop_back();
            }
        }
    }
};