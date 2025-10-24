class Solution {
private:
    vector<vector<int>> verticalSum;
    bool canMakeSquareOfSize(int size){ 
        const auto& s = verticalSum;

        for(int r = 0; r + size < verticalSum.size(); r++){
            for(int c = 0; c + size - 1 < verticalSum.front().size(); c++) {
                bool fail = false;
                for(int c2 = c; c2 < c + size; c2++){
                    if(verticalSum[r + size][c2] - verticalSum[r][c2] != size){
                        fail = true;
                        break;
                    }
                }

                if(!fail) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        verticalSum.resize(matrix.size() + 1, vector<int>(matrix.front().size(), 0));

        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                verticalSum[r + 1][c] += verticalSum[r][c] + matrix[r][c] - '0';
            }
        }
        
        const auto& s = verticalSum;

        for(int i = matrix.size(); i >= 0; i--) {
            if(canMakeSquareOfSize(i)){
                return i * i;
            }
        }

        return 0;
    }
};