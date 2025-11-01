class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int r = 0; r < matrix.size(); r++) {
            const vector<int>& row = matrix[r];
            const auto& lb = lower_bound(row.begin(), row.end(), target);
            const auto& ub = upper_bound(row.begin(), row.end(), target);
            if(lb == ub) {
                continue;
            }
            return true;
        }

        return false;
    }
};