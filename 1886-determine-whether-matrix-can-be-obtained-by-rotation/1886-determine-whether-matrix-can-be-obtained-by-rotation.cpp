class Solution {
private:
    bool eqeq(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
        for(int r = 0; r < mat1.size(); r++) {
            for(int c = 0; c < mat1.front().size(); c++) {
                if(mat1[r][c] != mat2[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }
    void transpose(vector<vector<int>>& mat) {
        for(int r = 0; r < mat.size(); r++) {
            for(int c = r + 1; c < mat.front().size(); c++) {
                swap(mat[r][c], mat[c][r]);
            }
        }
    }
    void reverseCols(vector<vector<int>>& mat) {
        for(int c = 0; c < mat.front().size(); c++) {
            for(int r = 0; r < mat.size() / 2; r++) {
                int end = mat.size() - r - 1;
                swap(mat[r][c], mat[end][c]);
            }
        }
    }
    void rotate90(vector<vector<int>>& mat) {
        transpose(mat);
        reverseCols(mat);
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            rotate90(mat);
            if(eqeq(mat, target)) {
                return true;
            }
        }
        return false;
    }
};