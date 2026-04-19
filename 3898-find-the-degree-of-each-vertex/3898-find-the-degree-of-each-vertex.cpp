class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res(matrix.size());
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res.size(); j++) {
                res[i] += matrix[i][j];
            }
        }

        return res;
    }
};