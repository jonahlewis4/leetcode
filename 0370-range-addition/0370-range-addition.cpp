class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> sweepLine(length + 1, 0);
        for(const vector<int>& update : updates) {
            int startIdx = update.front();
            int endIdx = update[1];
            int amt = update.back();
            sweepLine[startIdx] += amt;
            sweepLine[endIdx + 1] -= amt;
        }
        vector<int> res(length);
        res.front() = sweepLine.front();
        for(int i = 1; i < res.size(); i++) {
            res[i] = sweepLine[i] + res[i - 1];
        }
        return res;

    }
};