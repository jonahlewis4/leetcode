class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        calc(0, target, candidates, res, cur);
        return res;
        
    }
    void calc(int i, int target, const vector<int>& candidates, vector<vector<int>>& results, vector<int> &cur){
        if(target == 0){
            results.push_back(cur);
            return;
        }
        if(i >= candidates.size()){
            return;
        }
        if(target < 0){
            return;
        }
        cur.push_back(candidates[i]);
        calc(i + 1, target - cur.back(), candidates, results, cur);
        cur.pop_back();

        int skip = candidates[i];
        while(i < candidates.size() && candidates[i] == skip){
            i++;
        }
        calc(i, target, candidates, results, cur);
        
    }
};