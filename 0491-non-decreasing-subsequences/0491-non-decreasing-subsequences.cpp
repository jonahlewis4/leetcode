class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> used;
        vector<vector<vector<int>>> cache(nums.size());
        for(int i = nums.size() - 2; i >= 0; i--) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] >= nums[i]) {
                    vector<int> next = {nums[j], nums[i]};
                     if(!used.contains(next)) {
                        used.insert(next);
                        cache[i].push_back(next);
                    }
                    for(vector<int> next : cache[j]) {
                        next.push_back(nums[i]);
                        if(!used.contains(next)) {
                            used.insert(next);
                            cache[i].push_back(next);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(const vector<int>& v : used) {
            res.push_back(v);
        }
        for(vector<int>& v : res) {
            reverse(v.begin(), v.end());
        }
        return res;
    }
};