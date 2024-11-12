class Solution {
public:
    int uniquePaths(int m, int n) {
        int squares[m + 1][n + 1];
        squares[m][n - 1] = 1;
        for(int i = 0; i < m; i++){
            squares[i][n] = 0;
        }
        for(int i = 0; i < n; i++){
            squares[m][i] = 0;
        }
        squares[m][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                squares[i][j] = squares[i + 1][j] + squares[i][j + 1];
            }
        }

        return squares[0][0];
    }
};