class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        calc(0, res, candidates, comb, target);
        return res;
    }

    void calc(const int i, vector<vector<int>> &res, const vector<int>& candidates, vector<int> &comb, const int val){
        if(val == 0){
            res.push_back(comb);
        } else if (val < 0){
            return;
        }

        for(int j = i; j < candidates.size(); j++){
            comb.push_back(candidates[j]);
            calc(j, res, candidates, comb, val - candidates[j]);
            comb.pop_back();
        }
    }

};