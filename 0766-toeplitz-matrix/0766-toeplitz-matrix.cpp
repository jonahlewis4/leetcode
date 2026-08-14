class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int c = 0; c < matrix.front().size(); c++) {
            int start = matrix.front()[c];
            for(int r=0, localC = c; r < matrix.size() && localC < matrix.front().size(); r++, localC++) {
                if(matrix[r][localC] != start) {
                    
                    return false;
                }
            }
        }

        for(int r = 1; r < matrix.size(); r++) {
            int start = matrix[r].front();
            for(int localR=r, c = 0; localR < matrix.size() && c < matrix.front().size(); localR++, c++) {
                if(matrix[localR][c] != start) {
                    return false;
                }
            }
        }

        return true;
    }
};