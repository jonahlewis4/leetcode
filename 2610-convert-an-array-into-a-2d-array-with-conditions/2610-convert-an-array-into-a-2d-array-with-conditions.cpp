class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> nextRow;

        vector<vector<int>> res;
        for(const int num : nums) {
            int row = nextRow[num];
            nextRow[num]++;
            if(row >= res.size()) {
                res.emplace_back();
            } 
            res[row].emplace_back(num);
        }

        return res;
    }
};