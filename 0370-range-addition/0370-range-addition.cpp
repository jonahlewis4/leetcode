class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(const vector<int>& update : updates) {
            int startIdx = update.front();
            int endIdx = update[1];
            int amt = update.back();
            res[startIdx] += amt;
            if(endIdx + 1 < res.size()) {
                res[endIdx + 1] -= amt;
            }
        }
        for(int i = 1; i < res.size(); i++) {
            res[i] += res[i - 1];
        }
        return res;

    }
};