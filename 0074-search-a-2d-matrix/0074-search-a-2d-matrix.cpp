class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rowCount = matrix.size();
        int colCount = matrix.front().size();
        
        int l = 0;
        int r = rowCount * colCount - 1;
        while(l <= r) {
            int m = l + (r - l)/2;
            
            //flatten m to row and column
            int row = m / colCount;
            int col = m - row * colCount; 

            int searchValue = matrix[row][col];

            if(target == searchValue) {
                return true;
            } else if (target < searchValue) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};