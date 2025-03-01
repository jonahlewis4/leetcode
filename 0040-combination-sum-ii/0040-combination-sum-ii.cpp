class Solution {
private:
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cand;
        sort(candidates.begin(), candidates.end());
        

        calc(0, cand, res, candidates, target);
        return res;
    }
    
    void calc(int i, vector<int>& cand, vector<vector<int>>& res, const vector<int>& candidates, const int target){
        if(target == 0){
            res.push_back(cand);
            return;
        } else if (target < 0){
            return;
        }
        if(i >= candidates.size()){
            return;
        }
        
        cand.push_back(candidates[i]);
        calc(i + 1, cand, res, candidates, target - candidates[i]);
        cand.pop_back();

        i++;
        while(i < candidates.size() && candidates[i] == candidates[i - 1]){
            i++;
        }
        calc(i, cand, res, candidates, target);
    }   
    
    
    
    
    string hash(vector<int>& key){
        string res = "";
        for(const char c : key){
            res += c;
            res += '.';
        }
        return res;
    }
};