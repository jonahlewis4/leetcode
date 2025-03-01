class Solution {
private:
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> freq;
        vector<vector<int>> res;
        vector<int> cand;
        sort(candidates.begin(), candidates.end());
        for(const int i : candidates){
            freq[i]++;
        }

        const auto candidatesNoDup = removeDupFromSorted(candidates);
        calc(0, cand, res, candidatesNoDup, target, freq);
        return res;
    }
    vector<int> removeDupFromSorted(const vector<int> &list){
        vector<int> ans;
        for(int i = 0; i < list.size(); i++){
            if(i > 0 && list[i - 1] == list[i]){
                continue;
            }
            ans.push_back(list[i]);
        }
        return ans;
    }
    void calc(const int i, vector<int>& cand, vector<vector<int>>& res, const vector<int>& candidates, const int target, unordered_map<int, int>& freq){
        if(target == 0){
            res.push_back(cand);
        } else if (target < 0){
            return;
        }
        if(i > candidates.size()){
            return;
        }
        

        for(int j = i; j < candidates.size(); j++){
            int newTarget = target;
            for(int k = 0; k < freq[candidates[j]]; k++){
                cand.push_back(candidates[j]);
                newTarget -= candidates[j];
                calc(j + 1, cand, res, candidates, newTarget, freq);
            }
            for(int k = 0; k < freq[candidates[j]]; k++){
                cand.pop_back();
            }
        }
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