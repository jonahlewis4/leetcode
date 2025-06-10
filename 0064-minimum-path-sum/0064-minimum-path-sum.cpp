class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rc = grid.size(); 
        int cc = grid[0].size();
       

        for(int r = rc - 1; r >= 0; r--){
            for(int c = cc - 1; c >= 0; c--){
                int below = INT_MAX;
                int right = INT_MAX;
                if(c + 1 < cc){
                    right = grid[r][c + 1];
                } else if (r == rc - 1 && c == cc - 1) {
                    right = 0;
                }
                if(r + 1 < rc) {
                    below = grid[r + 1][c];
                }

                grid[r][c] = min(below, right) + grid[r][c];
            }
        }
        return grid[0][0];
    }
};