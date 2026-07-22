class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int area = mat.size() * mat.front().size();
        if(area != r * c) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c));
        int i = 0;
        int j = 0;
        for(const vector<int>& row : mat) {
            for(const int col : row) {
                res[i][j] = col;
                j++;
                if(j >= c) {
                    j = 0;
                    i++;
                }
            }
        }

        return res;
    }
};