class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool zeroRow = false;

        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                if(matrix[r][c] == 0){

                    
                    matrix[0][c] = 0;
                

                    if(r == 0){
                        zeroRow = true;
                    } else {
                        matrix[r][0] = 0;
                    }
                }
            }
        }

        
        for(int r = 1; r < matrix.size(); r++){
            if(matrix[r][0] == 0){
                fill(matrix[r].begin(), matrix[r].end(), 0);
            }
        }

        for(int c = 0; c < matrix[0].size(); c++){
            if(matrix[0][c] == 0){
                for(int r = 0; r < matrix.size(); r++){
                    matrix[r][c] = 0;
                }
            }
        }

        if(zeroRow){
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
    }
};