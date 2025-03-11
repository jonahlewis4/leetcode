class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> used;
        calc(cur, res, nums, used);
        return res;
    }
    void calc(vector<int>& cur, vector<vector<int>>&res, const vector<int>& nums, unordered_set<int> &used) const{
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(const int num : nums){
            if(used.find(num) != used.end()){
                continue;
            }
            used.insert(num);
            cur.push_back(num);
            calc(cur, res, nums, used);
            used.erase(num);
            cur.pop_back();
        }

    }
};