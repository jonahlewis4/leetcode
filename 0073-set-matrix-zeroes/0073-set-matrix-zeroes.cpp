class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstCol = false;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                if(matrix[r][c] == 0){
                    if(c == 0){
                        firstCol = true;
                    } else {
                        matrix[0][c] = 0;
                    }
                    matrix[r][0] = 0;
                }
            }
        }

        for(int c = 1; c < matrix[0].size(); c++){
            if(matrix[0][c] == 0){
                for(int r = 1; r < matrix.size(); r++){
                    matrix[r][c] = 0;
                }
            }
        }
        for(int r = 0; r < matrix.size(); r++){
            if(matrix[r][0] == 0){
                for(int c = 1; c < matrix[r].size(); c++){
                    matrix[r][c] = 0;
                }
            }
        }
        if(firstCol){
            for(int r = 0; r < matrix.size(); r++){
                matrix[r][0] = 0;
            }
        }

    }
};