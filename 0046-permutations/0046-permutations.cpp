class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        calc(res, cur, nums);
        return res;
    }
    void calc(vector<vector<int>>& res, vector<int>& cur, const vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            bool found = false;
            for(int j = 0; j < cur.size(); j++){
                if(cur[j] == nums[i]){
                    found = true;
                    break;
                }
            }
            if(!found){
                cur.push_back(nums[i]);
                calc(res, cur, nums);
                cur.pop_back();
            }
        }
    }
};