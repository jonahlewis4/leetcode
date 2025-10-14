class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix.front().size();

        //find which row that the target belongs in

        int bottom = 0;;
        int top = rowCount - 1;

        int row = -1;
        while(bottom <= top) {
            int mid = (top + bottom) / 2;
            if(target >= matrix[mid].front() && target <= matrix[mid].back()){
                row = mid;
                break;
            } else if (target >= matrix[mid].back()) {
                bottom = mid + 1;
            } else {
                top = mid - 1;
            }
        }
        if(row == -1) {
            return false;
        }

        const vector<int>& theRow = matrix[row];
        int l = 0;
        int r = theRow.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            int value = theRow[m];
            if(value == target) {
                return true;
            } else if (value < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
};