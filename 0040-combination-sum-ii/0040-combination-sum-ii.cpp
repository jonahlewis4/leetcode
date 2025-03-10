class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        calc(0, res, cur, target, candidates);
        return res;
    }
    void calc(int i, vector<vector<int>> &res, vector<int> &cur, int target, vector<int> &candidates){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        if(target < 0){
            return;
        }
        if(i >= candidates.size()){
            return;
        }

        //use and move to next one or don't use

        cur.push_back(candidates[i]);
        calc(i + 1, res, cur, target - cur.back(), candidates);
        cur.pop_back();

        int skip = candidates[i];
        while(i < candidates.size() && candidates[i] == skip ){
            i++;
        }
        calc(i, res, cur, target, candidates);
    }
};