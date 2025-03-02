class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        calc(res, cur, nums);
        return res;

        
    }
    void calc(vector<vector<int>>& res, vector<int>& cur, const vector<int>& nums){
        
        for(const int i : nums){
            bool alreadyInCur = false;
            for(const int j : cur){
                if(i == j){
                    alreadyInCur = true;
                    break;
                }
            }
            if(alreadyInCur){
                continue;
            }
            cur.push_back(i);
            if(cur.size() == nums.size()){
                res.push_back(cur);
            }
            calc(res, cur, nums);
            cur.pop_back();
        }
    }
};