class Solution {
private:
    vector<vector<char>> grid;
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                sum += dfs(i, j);
            }
        }
        return sum;
    }
    int dfs(int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()){
            return 0;
        }
        if(grid[i][j] == '1'){
            grid[i][j] = 0;
            dfs(i + 1, j);
            dfs(i, j + 1);
            dfs(i - 1, j);
            dfs(i, j - 1);
            return 1;
        }

        return 0;
    }
};