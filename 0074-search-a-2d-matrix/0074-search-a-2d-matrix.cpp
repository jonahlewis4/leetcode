class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();

        int top = 0;
        int bottom = rowCount - 1;
        int left = 0;
        int right = colCount - 1;


        int row = -1;
        while(top <= bottom){
            int mid = (top + bottom) / 2;
            if(matrix[mid][left] <= target && target <= matrix[mid][right]){
                row = mid;
                break;
            }

            if(target < matrix[mid][left]){
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }

        if(row == -1){
            return false;
        }


        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            if(target < matrix[row][mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};