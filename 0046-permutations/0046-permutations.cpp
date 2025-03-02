class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> notUsed;
        for(const int num : nums){
            notUsed.insert(num);
        }
        calc(res, cur, notUsed, nums);
        return res;

        
    }
    void calc(vector<vector<int>>& res, vector<int>& cur, unordered_set<int>& notUsed, const vector<int>& nums){
        vector<int> avail;
        for(const int i : nums){
            if(notUsed.find(i) == notUsed.end()){
                continue;
            }
            cur.push_back(i);
            if(cur.size() == nums.size()){
                res.push_back(cur);
            }
            notUsed.erase(i);
            calc(res, cur, notUsed, nums);
            cur.pop_back();
            notUsed.insert(i);
        }
    }
};