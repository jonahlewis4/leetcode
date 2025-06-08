class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        prefix[1][1] = 0;
        const auto & _prefix = prefix;
        for(int r = 0; r < matrix.size(); r++){
            int left = 0;
            for(int c = 0; c < matrix[r].size(); c++){
                prefix[r + 1][c + 1] = prefix[r][c + 1] + matrix[r][c] + left;
                left += matrix[r][c]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        const auto & _prefix = prefix;
        int full = prefix[row2 + 1][col2 + 1];
        int top = prefix[row1][col2 + 1];
        int left = prefix[row2 + 1][col1];
        int topLeft = prefix[row1][col1];
        return full - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */