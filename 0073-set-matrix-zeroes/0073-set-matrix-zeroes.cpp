class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;

        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                if(matrix[r][c] == 0){
                    zeroRows.insert(r);
                    zeroCols.insert(c);
                }
            }
        }


        for(const auto & r : zeroRows) {
            fill(matrix[r].begin(), matrix[r].end(), 0);
        }

        for(const auto & c : zeroCols) {
            for(int r = 0; r < matrix.size(); r++){
                matrix[r][c] = 0;
            }
        }
    }
};