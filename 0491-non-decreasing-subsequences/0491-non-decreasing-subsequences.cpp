class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<string> used;
        vector<vector<string>> cache(nums.size());
        for(int i = nums.size() - 2; i >= 0; i--) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] >= nums[i]) {
                    string next = to_string(nums[j]) + "." + to_string(nums[i]);
                     if(!used.contains(next)) {
                        used.insert(next);
                        cache[i].push_back(next);
                    }
                    for(const string& s : cache[j]) {
                        string next = s + "."  + to_string(nums[i]);
                        if(!used.contains(next)) {
                            used.insert(next);
                            cache[i].push_back(next);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(const string s : used) {
            res.push_back({});
            int cur = 0;
            int pow = 1;
            for(int i = s.size() - 1; i >= 0; i--) {
                if(s[i] == '-'){
                    cur = -cur;
                    continue;
                }
                if(s[i] == '.'){
                    res.back().push_back(cur);
                    cur = 0;
                    pow = 1;
                    continue;

                }
                cur += pow * (s[i] - '0');
                pow *= 10;
            }
            res.back().push_back(cur);
        }
        return res;
    }
};