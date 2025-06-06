class Solution {
    vector<vector<int>> matrix;
    int longest = 1;
    vector<vector<int>> dp;

    vector<tuple<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    int search(int r, int c) {

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int largestNeigh = 0;
        for(const auto & dir : dirs) {
            const auto & [rOff, cOff] = dir;
            int newR = r + rOff;
            int newC = c + cOff;

            if(newR < 0 || newC < 0 || newR >= matrix.size() || newC >= matrix[r].size()){
               continue;
            }

            if(matrix[newR][newC] <= matrix[r][c]){
                continue;
            }

            largestNeigh = max(largestNeigh, search(newR, newC));
        }

        longest = max(longest, largestNeigh + 1);
        dp[r][c] = largestNeigh + 1;
        return largestNeigh + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& _matrix) {
        matrix = _matrix;

        dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1)); 
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                search(r, c);
            }
        }

        return longest;
    }
};