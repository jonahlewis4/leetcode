class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottomR = matrix.size() - 1;
        int bottomC = 0;

        int topR = 0;
        int topC = matrix.front().size() - 1;

        while(bottomR >= topR && bottomC <= topC){
            int bVal = matrix[bottomR][bottomC];
            if(bVal == target) {
                return true;
            }

            int tVal = matrix[topR][topC];
            if(tVal == target) {
                return true;
            }

            if(bVal > target){
                bottomR--;
            } else {
                bottomC++;
            }

            if(tVal > target) {
                topC--;
            } else {
                topR++;
            }
        }

        return false;
    }
};