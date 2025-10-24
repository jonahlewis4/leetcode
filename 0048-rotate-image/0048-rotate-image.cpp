class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int midRow = (matrix.size() - 1) / 2;
        
        const auto& swapTillBack = [&matrix](int r, int c) {
            int topLR = r;
            int topLC = c;
            int topRR = c;
            int topRC = matrix.size() - r - 1;
            int botRR = matrix.size() - r - 1;
            int botRC = matrix.size() - c - 1;
            int botLR = matrix.size() - c - 1;
            int botLC = r;

            int temp = matrix[topLR][topLC];
            matrix[topLR][topLC] = matrix[botLR][botLC];
            matrix[botLR][botLC] = matrix[botRR][botRC];
            matrix[botRR][botRC] = matrix[topRR][topRC];
            matrix[topRR][topRC] = temp;

        };

        
        for(int r = 0; r <= midRow; r++){
            for(int c = r; c < matrix.size() - r - 1; c++){
                swapTillBack(r, c);
            }
        }
    }
};