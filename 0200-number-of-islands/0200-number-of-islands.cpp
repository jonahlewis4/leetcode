class Solution {
private:
    vector<vector<char>> _grid;
public:
    int numIslands(vector<vector<char>>& grid) {
        _grid = grid;
        int count = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(_grid[row][col] == '1'){
                    count++;
                    setAllTo0(row, col);
                }
            }
        }
        return count;
    }
    void setAllTo0(const int row, const int col){
            if(row < 0 || col < 0 || row >= _grid.size() || col >= _grid[row].size()){
                return;
            }
            if(_grid[row][col] == '0'){
                return;
            }
            _grid[row][col] = '0';
            setAllTo0(row + 1, col);
            setAllTo0(row - 1, col);
            setAllTo0(row, col + 1);
            setAllTo0(row, col - 1);

    }
};