class Solution {
private:
    vector<vector<char>> grid;
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(this->grid[i][j] == '1'){
                    dfs(i, j);
                    sum++;
                }   
            }
        }
        return sum;
    }
    void dfs(int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()){
            return;
        }
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            dfs(i + 1, j);
            dfs(i, j + 1);
            dfs(i - 1, j);
            dfs(i, j - 1);
        }
        return;
    }
};