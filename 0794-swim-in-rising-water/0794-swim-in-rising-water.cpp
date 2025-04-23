class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0;
        int r = n * n - 1;
        int res = INT_MIN;
        while(l <= r){
            int m = (l + r) / 2;
            if(canReach(m, grid)){
                //if we can reach we need to try smaller options
                res = m;
                r = m - 1;
            } else {
                //if we cannot reach, we need to try larger options.
                l = m + 1;
            }
        }
        return res;
    }
    bool canReach(int maxDepth, const vector<vector<int>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        return dfs(maxDepth, grid, visited, 0, 0);
    }
    bool dfs(int maxDepth, const vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c) const {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size()){
            return false;
        }
        if(grid[r][c] > maxDepth){
            return false;
        }
        if(r == grid.size() - 1 && c == grid[r].size() - 1){
            return true;
        }
        if(visited[r][c]){
            return false;
        }
        visited[r][c] = true;
        



        bool below = dfs(maxDepth, grid, visited, r + 1, c);
        bool above = dfs(maxDepth, grid, visited, r - 1, c);
        bool left = dfs(maxDepth, grid, visited, r, c - 1);
        bool right = dfs(maxDepth, grid, visited, r, c + 1);
        
        return below || above || left || right;
        
    }

};